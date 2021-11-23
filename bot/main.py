from random import randint, choice
from telethon import *
from telethon.tl.custom import *

import json
with open('model.json', encoding='UTF8') as fp:
    model = json.load(fp)

bot = TelegramClient( , , )


@bot.on(events.NewMessage())
async def start_command(event: Message):
    word = str(event.raw_text).lower()
    k = word + ' '
    try:
        while 1:
            print(word)
            b = choice(model[word])
            k += b
            k += ' '
            word = b
    except:
        pass
    await event.reply(k)


def main():
    bot.start(bot_token=<BOT_TOKEN>)
    bot.run_until_disconnected()


if __name__ == '__main__':
    main()
