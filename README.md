# Dev86's Discord Command Processor

(Dev86's fork of George's fork of inn0cent's Discord Command Control)

# What is DCC?

DCC is a command processor for discord bots in use with madd1nat0r's discord-connector plugin.

# What did i change?

DCC V2 was made for the sake of it to be compatible with discord-connector version 0.3.2, but the library had flaws that made it hard to get the command sender's author due to it returning the author's username as a string instead of DCC_User. I modified it so that it returns the author as DCC_User instead. With this modification, it would make it easier to get the author's account information (role, permissions, etc.).
With this modification, i added 2 new functions that makes role checking and getting the discord user's name string easier.
