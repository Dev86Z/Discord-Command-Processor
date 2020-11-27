# Devi's Discord Library (dv_discord)

Dev86's fork of George's fork of inn0cent's Discord Command Control

# Installation

You can install this using the package manager [sampctl](http://sampctl.com):

```sampctl package install sampdevi/dv_discord```

You can also install this the traditional way by including it in your script:
```pawn
#include <dv_discord>
```

# What is dv_discord?

dv_discord is fork of Discord Command Control (DCC) by inn0cent, which is a command processor for discord bots in use with [discord connector](https://github.com/maddinat0r/samp-discord-connector "praise j0sh").

# Usage

```pawn
DISCORD:test(DCC_Channel:channel, DCC_User:author, DCC_Message:message, DCC_Guild:guild, params[])
{
    // do stuff here
    return 1;
}
```

This library also makes the `DCC_` prefix on the [discord-connector](https://github.com/maddinat0r/samp-discord-connector) natives optional, meaning you can use `GetUserName` instead of `DCC_GetUserName`.
