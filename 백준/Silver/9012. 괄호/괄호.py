if __name__ == "__main__":
    n = int(input())

    for _ in range(n):
        opens = []
        wrong = False

        literal = input()

        for c in literal:
            if c == '(':
                opens.append(1)
            elif c == ')':
                if opens:
                    opens.pop()
                else:
                    wrong = True
                    break

        if wrong or opens:
            print("NO")
        else:
            print("YES")
