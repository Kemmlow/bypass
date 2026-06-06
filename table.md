| Target Function | Parent Subroutine | Purpose |
| --- | --- | --- |
| `AnoSDKGetReportData2` | `sub_5E031A8`, `sub_74A0058` | Report Data Retrieval |
| `AnoSDKIoctlOld` | `sub_640C054`, `sub_749F534`, `sub_74A03E4`, `sub_68CEC0C` | Legacy IO Control |
| `AnoSDKInit` | `sub_749F534` | AnoSDK Initialization |
| `AnoSDKOnResume` | - | Not called in libUE4.so |
| `AnoSDKOnRecvSignature` | `sub_74A0A00` | Signature Verification |
| `AnoSDKGetReportData` | `sub_74A0B34` | Standard Report Data |
| `AnoSDKDelReportData` | `sub_74A0B34` | Report Cleanup |
| `AnoSDKOnRecvData` | `sub_74A0BB8` | Network Data Handling |
| `AnoSDKIoctl` | - | Not called as standalone in libUE4.so |
