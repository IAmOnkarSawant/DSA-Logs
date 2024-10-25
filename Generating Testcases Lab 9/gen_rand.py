from random import randint

TEST_CASES = randint(1, 5)
print(TEST_CASES)

for _ in range(TEST_CASES):
    n = randint(1, 5_000)
    m = randint(1, n)
    k = randint(1, n // m)
    print(n, m, k)

    p = [randint(0, 1_000_000_000) for _ in range(n)]
    print(*p)
