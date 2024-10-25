from random import randint

MAX_TEST_CASES = 25
MAX_SUM_N = 2500

for file_num in range(6, 16): 
    with open(f'input{file_num}.txt', 'w') as f:
        test_cases = randint(1, MAX_TEST_CASES)
        f.write(f"{test_cases}\n")
        
        remaining_n_sum = MAX_SUM_N
        
        for case_num in range(1, test_cases + 1):
            if case_num == test_cases:
                n = remaining_n_sum  
            else:
                n = randint(1, min(5000, remaining_n_sum - (test_cases - case_num)))

            remaining_n_sum -= n
            
            m = randint(1, n)
            k = randint(1, n // m)

            f.write(f"{n} {m} {k}\n")

            p = [randint(0, 1_000_00) for _ in range(n)]
            f.write(" ".join(map(str, p)) + "\n")
