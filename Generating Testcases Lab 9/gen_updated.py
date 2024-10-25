from random import randint

MAX_TEST_CASES = 25
MAX_SUM_N = 2500
MAX_ELEMENT_SUM = 10**9 + 7

for file_num in range(6, 16):
    with open(f'input{file_num}.txt', 'w') as f:
        test_cases = randint(1, MAX_TEST_CASES)
        f.write(f"{test_cases}\n")

        remaining_n_sum = MAX_SUM_N
        total_sum_of_elements = 0  

        for case_num in range(1, test_cases + 1):
            if case_num == test_cases:
                n = remaining_n_sum
            else:
                n = randint(1, min(5000, remaining_n_sum - (test_cases - case_num)))

            remaining_n_sum -= n

            m = randint(1, n)
            k = randint(1, n // m)

            f.write(f"{n} {m} {k}\n")

            p = []
            current_sum = 0
            for _ in range(n):
                max_value = min(1_000_000, MAX_ELEMENT_SUM - total_sum_of_elements - current_sum)
                if max_value <= 0:
                    value = 0
                else:
                    value = randint(0, max_value)
                p.append(value)
                current_sum += value

            total_sum_of_elements += current_sum

            f.write(" ".join(map(str, p)) + "\n")

            if total_sum_of_elements >= MAX_ELEMENT_SUM:
                break
