# Keyboard Row
row1 = set('qwertyuiop')
row2 = set('asdfghjkl')
row3 = set('zxcvbnm')

words = ["Hello", "Alaska", "Dad", "Peace"]

ans = []


for i in words:
    if set(i.lower()) <= row1:
        ans.append(i)
    elif set(i.lower()) <= row2:
        ans.append(i)
    elif set(i.lower()) <= row3:
        ans.append(i)

print(ans)

