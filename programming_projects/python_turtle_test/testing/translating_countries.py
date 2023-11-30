from googletrans import Translator

translator = Translator()

countries = """
 Albania
 Belgium
 Bulgaria
 Canada
 Croatia
 Czech Republic
 Denmark
 Estonia
 Finland
 France
 Germany
 Greece
 Hungary
 Iceland
 Italy
 Latvia
 Lithuania
 Luxembourg
 Montenegro
 Netherlands
 North Macedonia
 Norway
 Poland
 Portugal
 Romania
 Slovakia
 Spain
 Turkey
 United Kingdom
 United States
"""

str_to_save = str()

for country in countries.split():
	str_to_save += f"{country} -> {translator.translate(country, dest='km').text}\n"

with open('./translated_countries.txt', 'w', encoding='utf-8') as f:
	f.write(str_to_save)
