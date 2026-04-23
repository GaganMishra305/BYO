import os
import subprocess

def test_step(DIR: str):
    for f in os.listdir(DIR):
        file_path = os.path.join(DIR, f)

        # run the code        
        result = subprocess.run(
            ["python3", "parser.py", file_path],
            capture_output=True,
            text=True
        )
        
        print(f"Testing: {f}", end = " ")
        try:
            if f.startswith('i'):
                assert result.returncode != 0, f"File-path {DIR + f} should have failed"
            else:
                assert result.returncode == 0, f"File-path {DIR + f} should have passed"
            print("PASSED")
        except AssertionError as e:
            print("FAILED")
            print("="*20, e, "="*20)

test_step("./tests/step1/")
test_step("./tests/step2/")
test_step("./tests/step3/")
test_step("./tests/step4/")
test_step("./tests/step5/")
