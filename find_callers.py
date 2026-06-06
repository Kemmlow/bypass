import re

targets = [
    "AnoSDKGetReportData2",
    "AnoSDKIoctlOld",
    "AnoSDKInit",
    "AnoSDKOnResume",
    "AnoSDKOnRecvSignature",
    "AnoSDKGetReportData",
    "AnoSDKDelReportData",
    "AnoSDKOnRecvData",
    "AnoSDKIoctl"
]

results = {}

current_sub = "Unknown"
with open("libUE4.so.c", "r") as f:
    for line in f:
        # Detect subroutine start
        sub_match = re.search(r'^(__int64|void|unsigned __int64|bool|int|char|short|float|double|long|signed __int64).*?\s(sub_[0-9A-F]+)\(', line)
        if sub_match:
            current_sub = sub_match.group(2)

        # Strip comments for search
        content = line.split("//")[0]

        for target in targets:
            # Use word boundaries to avoid name shadowing (e.g., AnoSDKIoctl matching AnoSDKIoctlOld)
            if re.search(rf'\b{target}\b', content):
                if target not in results:
                    results[target] = set()
                results[target].add(current_sub)

for target, subs in results.items():
    print(f"{target}: {', '.join(subs)}")
