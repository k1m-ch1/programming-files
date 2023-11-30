from googletrans import Translator
from googletrans import LANGUAGES

translator = Translator()
translated_text = translator.translate("Those are pretty much your mirror neurons.",dest='fr', src="en")
open(r'C:\Users\Kimchour\Documents\programming_projects\python\google_translate\output.txt', 'a', encoding='utf-8').write(translated_text.text)
