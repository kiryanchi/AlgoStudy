n = int(input())
cnt = 0
for _ in range(n):
    _str = input()
    duplicated = False
    char_dict = {}
    last_char = ''
    current_char = ''
    for c in _str:
        last_char = current_char
        current_char = c
        if not c in char_dict:
            char_dict[c] = 1
        else:
            if last_char != current_char:
                duplicated = True
                break
    if not duplicated:
        cnt += 1
print(cnt)