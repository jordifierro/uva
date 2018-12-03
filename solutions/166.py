import fileinput

def main():
    for line in fileinput.input():
        elements = [x for x in line.split()]
        number_of_coins = [int(elements[i]) for i in range(6)]
        if number_of_coins == [0, 0, 0, 0, 0, 0]:
            break

        amount = int(int(float(elements[6]) * 10000) / 500)

        coins_to_pay = [-1 for i in range(101)]
        coins_to_pay[0] = 0
        for i, coin_value in zip(range(6), [1, 2, 4, 10, 20, 40]):
            for j in range(number_of_coins[i]):
                for x in range(100 - coin_value, -1, -1):
                    if coins_to_pay[x] >= 0:
                        if coins_to_pay[x+coin_value] == -1:
                            coins_to_pay[x+coin_value] = coins_to_pay[x] + 1
                        else:
                            coins_to_pay[x+coin_value] = min(coins_to_pay[x] + 1, coins_to_pay[x+coin_value])

        coins_to_return = [-1 for i in range(101)]
        coins_to_return[0] = 0
        for coin_value in [1, 2, 4, 10, 20, 40]:
            for i in range(101 - coin_value):
                if coins_to_return[i] >= 0:
                    if coins_to_return[i+coin_value] == -1:
                        coins_to_return[i+coin_value] = coins_to_return[i] + 1
                    else:
                        coins_to_return[i+coin_value] = min(coins_to_return[i] + 1, coins_to_return[i+coin_value])

        minimum = 5000
        for i, coins_to_pay, coins_to_return in zip(range(10000), coins_to_pay[amount:], coins_to_return):
            if coins_to_pay >= 0 and coins_to_return >= 0:
                if coins_to_pay + coins_to_return < minimum:
                    index = i
                minimum = min(minimum, coins_to_pay + coins_to_return)

        print('{:>3s}'.format(str(minimum)))

if __name__ == '__main__':
    main()
