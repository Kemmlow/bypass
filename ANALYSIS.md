# libanogs.so Deep Recursive Analysis (BGMI Mobile)

This document provides a detailed, line-by-line, and recursive analysis of the functions exported by `libanogs.so`.

---

## 1. AnoSDKInit
**Address:** `0x64607`

### Overview
Bootstraps the Anti-Cheat SDK. It initializes the internal state machine, sets up the main context, and starts the monitoring subsystems.

### Line-by-Line Analysis
- **Entry:** Receives a context/result pointer in `X0`.
- **Initialization:** Sets up pointers to stack-allocated variables (`v13`, `v14`, `v15`) which are used to store intermediate calculation results for integrity checks.
- **State Machine:** Uses an `int v4` to manage control flow.
- **Opaque Predicate:** `(v6 | ~v5) + (v5 & v6) + (v5 & ~v6) + 1 != (v5 & v6)`. This is a constant truth/falsehood used to prevent simple static analysis of the jump path.
- **Core Call:** Calls `sub_1CA18C`. This function initializes the global SDK context `qword_574DE0` and `qword_574DE8`.
- **Monitor Setup:** Calls `sub_4D4C94(v16, 0)`. This initializes the "System Monitor" (Category 0).
- **Completion:** Loops until the state machine reaches the final state, ensuring all sub-initializers have finished.

### Security/Integrity Related: **YES**

---

## 2. AnoSDKGetReportData
**Address:** `0x65394`

### Overview
Retrieves accumulated detection reports from the SDK's internal telemetry buffers.

### Line-by-Line Analysis
- **State Machine:** Controlled by `v13`.
- **Category Access:** Calls `sub_4D4C94(1, 4)` to access the "Report" category of the monitor system.
- **Context Access:** Accesses global `qword_574DE0`.
- **Data Retrieval:** Calls `sub_1C264C`, which iterates through a linked list of report objects stored in the SDK's heap.
- **Recursive Logic:** `sub_1C264C` calls a virtual function at `[context + 80]` to get the start of the list.
- **Exit:** Returns a pointer to a serialized buffer containing the report data.

### Security/Integrity Related: **YES**

---

## 3. AnoSDKGetReportData2
**Address:** `0x66475`

### Overview
A secondary report retrieval interface, often used for high-priority or synchronous telemetry.

### Line-by-Line Analysis
- **Wrapper:** Calls `sub_1C79D4()`.
- **Recursive Logic (`sub_1C79D4`):**
    - Checks `qword_574DE0` for initialization.
    - If initialized, it calls a virtual function at `offset +40` of the context.
    - **Logging:** Calls `sub_4F7074` with the string `"get2:%d, %p"`. This is used for internal debugging of the reporting pipeline.
    - **Result:** Returns the data pointer obtained from the internal reporting engine.

### Security/Integrity Related: **YES**

---

## 4. AnoSDKDelReportData
**Address:** `0x65580`

### Overview
Acknowledges and deletes report data after it has been sent to the server.

### Line-by-Line Analysis
- **Parameter:** `a1` is the pointer to the data to be deleted.
- **State Machine:** Controlled by `v18`.
- **Categorization:** Identifies the report type (e.g., `12502`, `12506`).
- **Notification:** Calls `sub_4D4C94(1, 5)` to notify the monitor that data is being cleared.
- **Freeing:** Calls `loc_1C1DC4` to perform the actual memory deallocation.

### Security/Integrity Related: **YES**

---

## 5. AnoSDKOnResume
**Address:** `0x65223`

### Overview
Called when the game returns to focus. It re-arms the anti-cheat's periodic scanning threads.

### Line-by-Line Analysis
- **Periodic Trigger:** Calls `sub_1CB244(1)`.
    - `sub_1CB244` checks the SDK context and triggers internal security timers.
- **Monitor Resume:** Calls `sub_4D4C94(1, 3)` (Category 3: Background Monitor).
- **Integrity Check:** Performs a bitwise check `v5 - 2 * v6 != v7` to ensure the function's stack wasn't modified during the resume process.

### Security/Integrity Related: **YES**

---

## 6. AnoSDKOnRecvSignature
**Address:** `0x66883`

### Overview
Processes dynamic detection signatures received from the game server.

### Line-by-Line Analysis
- **Signature Processing:** Calls `sub_1CD404(a1, a2, a3, a4)`.
- **Recursive Logic (`sub_1CD404`):**
    - Uses `loc_1C5B70(34, ...)` to verify the cryptographic signature of the incoming data.
    - Uses `loc_1C5B70(83, ...)` to load the verified rules into the anti-cheat engine.
- **Integrity:** Returns a result adjusted by a constant `30811`, used as a simple checksum by the caller.

### Security/Integrity Related: **YES**

---

## 7. AnoSDKOnRecvData
**Address:** `0x65802`

### Overview
Receives raw data from the server or other game components and routes it to the appropriate SDK handler.

### Line-by-Line Analysis
- **Validation:** Ensures data pointer `a1` is not NULL and length `a2` is non-negative.
- **Logging:** Calls `sub_4D4C94(..., 6)` to log the data reception.
- **Dispatch:** Calls `sub_1C3310`.
    - `sub_1C3310` looks up a callback function at `[qword_574DE0 + 48]` and passes the data to it.

### Security/Integrity Related: **YES**

---

## 8. AnoSDKIoctl
**Address:** `0x66182`

### Overview
Primary control interface for the SDK. Used for everything from querying emulator status to triggering memory scans.

### Line-by-Line Analysis
- **Dispatcher:** Calls `sub_1C8D00(a1, a2)`.
- **Recursive Logic (`sub_1C8D00`):**
    - **Emulator Check:** Uses `loc_1C5B70(10, ...)` and builds a string like `"|emulator_name=..."`.
    - **System Info:** Uses `loc_1C5B70(18, ...)` to get hardware/system fingerprints.
    - **Integrity Check:** Uses `loc_1C5B70(45, ...)` to trigger a re-scan of game memory.
- **Strings:** Uses `sub_4B6C94` (sprintf) and `sub_4B60D4` (strcat) to format telemetry.

### Security/Integrity Related: **YES**

---

## 9. AnoSDKIoctlOld
**Address:** `0x65856`

### Overview
Legacy IOCTL handler. Highly obfuscated to hide older detection methods.

### Line-by-Line Analysis
- **Obfuscation:** Uses the most complex control-flow flattening in the library (`v30` state variable).
- **Parameter Packing:** Arguments are packed into a 128-byte stack structure.
- **JUMPOUT:** Almost every branch eventually executes `JUMPOUT(0x1C5B70LL)`.
- **Dispatcher:** It is essentially a "proxy" that forwards legacy commands to the modern `loc_1C5B70` dispatcher.

### Security/Integrity Related: **YES**

---

## Master Dispatcher Table: `loc_1C5B70`
This internal routine handles the core "privileged" tasks for the SDK.

| ID | Purpose | Security Relevance |
| :--- | :--- | :--- |
| 1 | Secure Initialization | YES |
| 4 | Device ID Query | YES |
| 10 | Emulator Detection | YES |
| 16 | Memory Integrity | YES |
| 18 | Fingerprinting | YES |
| 35 | Anti-Debug Check | YES |
| 36 | Hook Detection | YES |
| 45 | Full Integrity Scan | YES |
| 56 | Event Reporting | YES |
| 83 | Signature Update | YES |
| 85 | Error Assertion | YES |
