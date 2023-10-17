while True:
    li = []
    state = True
    S = input()
    if S == '.':
        break
    for s in S:
        if s == '(' or s == '[':
            li.append(s)
        elif s == ')':
            if li and li[-1] == '(':
                li.pop()
            else:
                state = False
                break
        elif s == ']':
            if li and li[-1] == '[':
                li.pop()
            else:
                state = False
                break

    if state and not li:
        print('yes')
    else:
        print('no')