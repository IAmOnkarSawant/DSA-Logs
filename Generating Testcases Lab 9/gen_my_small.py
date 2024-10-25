from random import randint

MAX_TEST_CASES = 5
MAX_SUM_N = 10

for file_num in range(21, 26):  # For generating 5 files
    # Open a file with the name input<number>.txt
    with open(f'input{file_num}.txt', 'w') as f:
        # Calculate the number of test cases, ensuring it's between 1 and 50
        test_cases = randint(1, MAX_TEST_CASES)
        
        # Write the number of test cases in the first line of the file
        f.write(f"{test_cases}\n")
        
        # Initialize the remaining sum of n
        remaining_n_sum = MAX_SUM_N
        
        for case_num in range(1, test_cases + 1):
            # Ensure that n is chosen such that the sum of n across all test cases doesn't exceed 25000
            if case_num == test_cases:
                n = remaining_n_sum  # Ensure the final case uses up the remaining sum
            else:
                n = randint(1, min(500, remaining_n_sum - (test_cases - case_num)))

            # Update remaining sum of n
            remaining_n_sum -= n
            
            m = randint(1, n)
            k = randint(1, n // m)

            # Write n, m, k values to the file
            f.write(f"{n} {m} {k}\n")

            # Generate the sequence p and write it to the file
            p = [randint(0, 1000) for _ in range(n)]
            f.write(" ".join(map(str, p)) + "\n")
