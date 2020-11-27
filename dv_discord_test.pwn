#include <a_samp>
#include <sscanf2>
#include <discord-connector>

#define GUILD_ID	"631654236106784780"
#include <dv_discord>

public OnFilterScriptInit()
{
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

DISCORD:test(DCC_Channel:channel, DCC_User:author, DCC_Message:message, DCC_Guild:guild, params[])
{
	new dcString[128],
		dcUser[64],
		dcChannel[64],
		dcGuild[64],
		dcMessage[DCC_ID_SIZE];

	dcUser = GetDiscordNameEx(author);
	GetChannelName(channel, dcChannel);
	GetGuildName(guild, dcGuild);
	GetMessageId(message, dcMessage);

	format(dcString, sizeof(dcString), 
		"**dv_discord DEBUG**\r \
		Channel: %s \r \
		Author: %s \r \
		Message: %s \r \
		Guild: %s",
		dcChannel, dcUser, dcChannel, dcGuild, dcMessage);

	SendChannelMessage(channel, dcString);
	return 1;
}