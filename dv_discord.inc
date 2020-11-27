#include <sscanf2>
#include <YSI\y_va>
#include <discord-connector>


#define DISCORD 	DCCMD
#define DC_CMD 		DCCMD
#define SendDC 		SendDiscordMessage
#define DCCMD:%0(%1,%2)          \
			forward dc_cmd_%0(%1,%2[]); \
			public dc_cmd_%0(%1,%2[])
			
forward OnDCCommandPerformed(args[], success);	

//Discord Channel Callback
new DCC_Channel:g_Discord_Command_Place;
new DCC_Channel:BotChannel;

forward SendDiscordMessage(channel[], const fmat[], va_args<>);
public SendDiscordMessage(channel[], const fmat[], va_args<>)
{
	new
        str[145];
    va_format(str, sizeof (str), fmat, va_start<2>);
	BotChannel = DCC_FindChannelById(channel);
    return DCC_SendChannelMessage(BotChannel, str);
}

forward DCC_OnMessageCreate(DCC_Message:message);
public DCC_OnMessageCreate(DCC_Message:message)
{
    new realMsg[100];
    DCC_GetMessageContent(message, realMsg, 100);
    new bool:IsBot;
    new DCC_Channel:channel;
    DCC_GetMessageChannel(message, channel);
    new DCC_User:author;
    DCC_GetMessageAuthor(message, author);
    DCC_IsUserBot(author, IsBot);
	g_Discord_Command_Place = DCC_FindChannelById(DISCORD_CHANNEL_ID);
    if(channel == g_Discord_Command_Place && !IsBot) //!IsBot will block BOT's message in discord like (Bot A : /ban 1 test")
    {
        new dmsg[10][128];
		explode(dmsg, realMsg, " ", 2);
		new command[10], args[50];
		sscanf(realMsg, "s[10]s[50]", command, args); // Sperate message in COMMAND and arguments.
		if(strfind(command, DISCORD_PREFIX, true) != -1) // Check if command have prefix defined above.
		{
			new funcdc[128];
			strdel(command, 0, 1);
			format(funcdc, sizeof(funcdc), "dc_cmd_%s", command); // Format function.
			
			if(isnull(dmsg[1])) {
				CallLocalFunction("OnDCCommandPerformed", "si", realMsg, CallLocalFunction(funcdc, "is", _: author, "\1"));
			} else CallLocalFunction("OnDCCommandPerformed", "si", realMsg, CallLocalFunction(funcdc, "is", _: author, args));
		}
    }

    return 1;
}

stock explode(aExplode[][], const sSource[], const sDelimiter[] = " ", iVertices = sizeof aExplode, iLength = sizeof aExplode[])
{
	new
		iNode,
		iPointer,
		iPrevious = -1,
		iDelimiter = strlen(sDelimiter);

	while(iNode < iVertices)
	{
		iPointer = strfind(sSource, sDelimiter, false, iPointer);

		if(iPointer == -1)
		{
			strmid(aExplode[iNode], sSource, iPrevious, strlen(sSource), iLength);
			break;
		}
		else
		{
			strmid(aExplode[iNode], sSource, iPrevious, iPointer, iLength);
		}

		iPrevious = (iPointer += iDelimiter);
		++iNode;
	}

	return iPrevious;
}

stock GetDiscordName(DCC_User:user)
{
	new pname_[32];
	DCC_GetUserName(user, pname_);
	return pname_;
}

stock UserHasRole(DCC_User:user, DCC_Role:role)
{
	new bool:value;
	new DCC_Guild:jGuild = DCC_FindGuildById(GUILD_ID);
	DCC_HasGuildMemberRole(jGuild, user, role, value);
	return value;
}
