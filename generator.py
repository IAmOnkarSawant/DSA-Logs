import os
import string
import random
def generate_test_cases_and_files():
    test_cases = []
    
    # Directory for inputs and outputs
    input_dir = "./test"
    os.makedirs(input_dir, exist_ok=True)
    
    # 1. Entire string has the same character (one short length, one long length)
    test_cases.append("aaaa")  # Short length
    test_cases.append("a" * 100000)  # Long length

    # 2. Edge cases
    # Edge Case 1: Only one character
    test_cases.append("a")
    
    # Edge Case 2: No repeating prefix-suffix
    test_cases.append("abcd")
    
    # Edge Case 3: Repeated pattern but not complete prefix-suffix
    test_cases.append("abacabad")
    
    # Edge Case 4: Alternating characters
    test_cases.append("abababab")

    # 3. Complexity tests which will break brute force code
    # Repeating pattern with long length
    test_cases.append("ab" * 50000)  # "abababab... (100000 characters)"
    
    # Mixed pattern with increasing lengths
    test_cases.append("abcabcabc" * 11111 + "x")  # Long pattern with small change

    # 4. Other complexity of variable lengths
    # Random string of medium length
    test_cases.append(''.join(random.choices(string.ascii_lowercase, k=500)))

    # Complex mix of repeated sequences and unique characters
    test_cases.append("abcd" * 100 + "efghijklmnopqrstuvwxyz" + "abcd" * 100)

    # Write input files
    for idx, case in enumerate(test_cases, 1):
        input_file = os.path.join(input_dir, f"input{idx}.txt")
        with open(input_file, "w") as f:
            f.write(case)

# Generate input files
generate_test_cases_and_files()
