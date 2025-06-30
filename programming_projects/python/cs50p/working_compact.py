import re, sys

class InvalidWorkingFormat(Exception): pass

main = lambda : print(convert(input('Hours: ')))

def convert_12h_to_24h(time_12h_format):
	if (matched:=re.search(r'^(0?[1-9]|1[0-2])\s*:?\s*([0-5][0-9])?\s*(am|pm)$', time_12h_format)) is None: raise InvalidWorkingFormat('format of the time is wrong')
	return "{:02d}".format(int(matched.group(1))%12 + {'am': 0, 'pm':12}[matched.group(3)])  + ':' +  ('00' if matched.group(2) is None else matched.group(2))


def convert(american_work_hour):
	if len(times:=[time.strip() for time in american_work_hour.lower().split('to')]) == 2: return (lambda a, b: a + ' to ' + b)(*[convert_12h_to_24h(t) for t in times])
	else: raise InvalidWorkingFormat("incorrect usage of 'to'")

if __name__ == "__main__": main()