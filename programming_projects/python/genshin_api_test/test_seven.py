def findShortestStr(strs):
        return sorted(map(lambda x: (len(x), x), strs))[0]

ml = ['apples', 'bananas', 'oranges', 'grape', 'chicken', 'pizza']
print(findShortestStr(ml))

