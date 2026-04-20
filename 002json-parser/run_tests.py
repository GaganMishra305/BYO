import os
import subprocess

def test_step1():
    DIR = "./tests/step1/"
    for f in os.listdir(DIR):
        file_path = os.path.join(DIR, f)

        # run the code        
        result = subprocess.run(
            ["python3", "parser.py", file_path],
            capture_output=True,
            text=True
        )
        
        print(f"Testing: {f}")
        if f.startswith('i'):
            assert result.returncode != 0, f"File {f} should have failed"
        else:
            assert result.returncode == 0, f"File {f} should have passed"

test_step1()