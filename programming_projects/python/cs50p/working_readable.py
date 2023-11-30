import re
import sys

class InvalidWorkingFormat(Exception):
	pass

def main():
	print(convert(input("Hours: ")))

def convert_12h_to_24h(time_12h_format):
	time_regex = r'^(0?[1-9]|1[0-2])\s*:?\s*([0-5][0-9])?\s*(am|pm)$'

	matched = re.search(time_regex, time_12h_format)
	if matched is None:
		raise InvalidWorkingFormat('format of the time is wrong')

	hour, minute, am_pm = matched.groups()
	add_factor = {'am':0, 'pm':12}
	hour = int(hour)%12 + add_factor[am_pm]
	return "{:02d}".format(hour)  + ':' +  ('00' if minute is None else minute)

def convert(american_work_hour):
	if len(times:=[time.strip() for time in american_work_hour.lower().split('to')]) == 2:
		start_work_time, end_work_time = times
		start_work_time = convert_12h_to_24h(start_work_time)
		end_work_time = convert_12h_to_24h(end_work_time)
		return start_work_time + ' to ' + end_work_time
	else:
		raise InvalidWorkingFormat("incorrect usage of 'to'")

if __name__ == "__main__":
	main()