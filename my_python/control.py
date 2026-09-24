import subprocess

result = subprocess.run(["df", "-h"], capture_output=True, text=True)


print("========Disk Usage Checking=======")
print(result.stdout)

