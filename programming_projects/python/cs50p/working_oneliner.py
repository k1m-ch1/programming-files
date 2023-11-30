import re, sys

class InvalidWorkingFormat(Exception): pass

main = lambda : print(convert(input('Hours: ')))

convert = lambda american_work_hour: exec(r"raise InvalidWorkingFormat('incorrect usage of \'to\'')") if len(times:=[time.strip() for time in american_work_hour.lower().split('to')]) != 2 else (lambda a, b: exec("raise InvalidWorkingFormat('format of the time is wrong')") if (a[1], b[1]).count(None) == 1 else a[0] + ':' + ('00' if a[1] is None else a[1]) + ' to ' + b[0] + ':' + ('00' if b[1] is None else b[1]))(*[(lambda time_12h_format: exec("raise InvalidWorkingFormat('format of the time is wrong')") if (matched:=re.search(r'^(0?[1-9]|1[0-2])\s*:?\s*([0-5][0-9])?\s*(am|pm)$', time_12h_format)) is None else ('{:02d}'.format(int(matched.group(1))%12  + {'am': 0, 'pm':12}[matched.group(3)]), matched.group(2)))(t) for t in times])

if __name__ == "__main__": main()