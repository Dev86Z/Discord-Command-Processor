#if defined _dv_discord_included
	#endinput
#endif
#define _dv_discord_included

/*
#if !defined _INC_SSCANF
	#error the following library was not found or loaded properly: sscanf2
#endif
*/
#tryinclude <discord-connector>
#if !defined dcconnector_included
	#error the following library was not found or loaded properly: discord-connector
#endif

#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define DISCORD:%1(%2) 			\
	DCCMD:%1(%2)

#define DC_CMD:%1(%2) 			\
	DCCMD:%1(%2)

#define DC:%1(%2) 			\
	DCCMD:%1(%2)

#define DC:%1(%2) 			\
	DCCMD:%1(%2)

#define DCCMD:%0(%1,%2)          		\
			forward dc_cmd_%0(%1,%2[]); \
			public dc_cmd_%0(%1,%2[])

#if !defined GUILD_ID
	#error the definition of "GUILD_ID" was not found. Please define your discord server's GUILD_ID.
#endif
			
#if !defined DISCORD_PREFIX
	#define DISCORD_PREFIX	"!"
#endif


#define FindChannelByName 			DCC_FindChannelByName
#define FindChannelById 			DCC_FindChannelById
#define GetChannelId 				DCC_GetChannelId
#define GetChannelType				DCC_GetChannelType
#define GetChannelGuild				DCC_GetChannelGuild
#define GetChannelName				DCC_GetChannelName
#define GetChannelTopic				DCC_GetChannelTopic
#define GetChannelPosition			DCC_GetChannelPosition
#define IsChannelNsfw				DCC_IsChannelNsfw
#define GetChannelParentCategory	DCC_GetChannelParentCategory
#define SendChannelMessage 			DCC_SendChannelMessage
#define SetChannelName				DCC_SetChannelName
#define SetChannelTopic				DCC_SetChannelTopic
#define SetChannelPosition			DCC_SetChannelPosition
#define SetChannelNsfw				DCC_SetChannelNsfw				
#define SetChannelParentCategory	DCC_SetChannelParentCategory
#define DeleteChannel				DCC_DeleteChannel
#define GetMessageId				DCC_GetMessageId
#define GetMessageChannel			DCC_GetMessageChannel
#define GetMessageAuthor			DCC_GetMessageAuthor
#define GetMessageContent			DCC_GetMessageContent
#define IsMessageTts				DCC_IsMessageTts
#define IsMessageMentioningEveryone	DCC_IsMessageMentioningEveryone
#define GetMessageUserMentionCount	DCC_GetMessageUserMentionCount
#define GetMessageUserMention 		DCC_GetMessageUserMention
#define GetMessageRoleMentionCount	DCC_GetMessageRoleMentionCount
#define GetMessageRoleMention 		DCC_GetMessageRoleMention
#define DeleteMessage 				DCC_DeleteMessage
#define GetCreatedMessage 			DCC_GetCreatedMessage
#define DeleteInternalMessage  		DCC_DeleteInternalMessage
#define EditMessage 				DCC_EditMessage
#define SetMessagePersistent		DCC_SetMessagePersistent
#define CacheChannelMessage			DCC_CacheChannelMessage
#define FindUserByName				DCC_FindUserByName
#define FindUserById				DCC_FindUserById
#define GetUserName					DCC_GetUserName
#define GetUserId 					DCC_GetUserId
#define GetUserDiscriminator		DCC_GetUserDiscriminator
#define IsUserBot					DCC_IsUserBot
#define IsUserVerified 				DCC_IsUserVerified
#define FindRoleByName				DCC_FindRoleByName
#define FindRoleById 				DCC_FindRoleById
#define GetRoleId 					DCC_GetRoleId
#define GetRoleName 				DCC_GetRoleName
#define GetRoleColor 				DCC_GetRoleColor
#define GetRoleColour				DCC_GetRoleColour
#define GetRolePermissions 			DCC_GetRolePermissions
#define IsRoleHoist 				DCC_IsRoleHoist
#define GetRolePosition				DCC_GetRolePosition
#define IsRoleMentionable 			DCC_IsRoleMentionable
#define FindGuildByName 			DCC_FindGuildByName
#define FindGuildById	  			DCC_FindGuildById
#define GetGuildId 					DCC_GetGuildId
#define GetGuildName 				DCC_GetGuildName
#define GetGuildOwnerId				DCC_GetGuildOwnerId
#define GetGuildRole 				DCC_GetGuildRole
#define GetGuildRoleCount 			DCC_GetGuildRoleCount
#define GetGuildMember 				DCC_GetGuildMember
#define GetGuildMemberCount  		DCC_GetGuildMemberCount
#define GetGuildMemberVoiceChannel 	DCC_GetGuildMemberVoiceChannel
#define GetGuildMemberNickname		DCC_GetGuildMemberNickname
#define GetGuildMemberRole 			DCC_GetGuildMemberRole
#define GetGuildMemberRoleCount		DCC_GetGuildMemberRoleCount
#define HasGuildMemberRole			DCC_HasGuildMemberRole
#define GetGuildMemberStatus		DCC_GetGuildMemberStatus
#define GetGuildChannel 			DCC_GetGuildChannel
#define GetGuildChannelCount 		DCC_GetGuildChannelCount
#define GetAllGuilds 				DCC_GetAllGuilds
#define SetGuildName 				DCC_SetGuildName
#define CreateGuildChannel 			DCC_CreateGuildChannel
#define GetCreatedGuildChannel 		DCC_GetCreatedGuildChannel
#define SetGuildMemberNickname 		DCC_SetGuildMemberNickname
#define SetGuildMemberVoiceChannel 	DCC_SetGuildMemberVoiceChannel
#define AddGuildMemberRole 			DCC_AddGuildMemberRole
#define RemoveGuildMemberRole 		DCC_RemoveGuildMemberRole
#define RemoveGuildMember  			DCC_RemoveGuildMember
#define CreateGuildMemberBan  		DCC_CreateGuildMemberBan
#define RemoveGuildMemberBan	 	DCC_RemoveGuildMemberBan
#define SetGuildRolePosition 		DCC_SetGuildRolePosition
#define SetGuildRoleName			DCC_SetGuildRoleName
#define SetGuildRolePermissions 	DCC_SetGuildRolePermissions
#define SetGuildRoleColor 			DCC_SetGuildRoleColor
#define SetGuildRoleHoist	 		DCC_SetGuildRoleHoist
#define SetGuildRoleMentionable		DCC_SetGuildRoleMentionable
#define CreateGuildRole 			DCC_CreateGuildRole
#define GetCreatedGuildRole 		DCC_GetCreatedGuildRole
#define DeleteGuildRole 			DCC_DeleteGuildRole
#define GetBotPresenceStatus 		DCC_GetBotPresenceStatus
#define TriggerBotTypingIndicator 	DCC_TriggerBotTypingIndicator
#define SetBotNickname 				DCC_SetBotNickname
#define CreatePrivateChannel 		DCC_CreatePrivateChannel
#define GetCreatedPrivateChannel 	DCC_GetCreatedPrivateChannel
#define SetBotPresenceStatus 		DCC_SetBotPresenceStatus
#define SetBotActivity 				DCC_SetBotActivity
#define EscapeMarkdown 				DCC_EscapeMarkdown
#define CreateEmbed 				DCC_CreateEmbed
#define DeleteEmbed 				DCC_DeleteEmbed
#define SendChannelEmbedMessage 	DCC_SendChannelEmbedMessage 	
#define AddEmbedField				DCC_AddEmbedField
#define SetEmbedTitle				DCC_SetEmbedTitle
#define SetEmbedDescription			DCC_SetEmbedDescription
#define SetEmbedUrl					DCC_SetEmbedUrl
#define SetEmbedTimestamp			DCC_SetEmbedTimestamp
#define SetEmbedColor 				DCC_SetEmbedColor
#define SetEmbedColour				DCC_SetEmbedColour
#define SetEmbedFooter				DCC_SetEmbedFooter
#define SetEmbedThumbnail			DCC_SetEmbedThumbnail
#define SetEmbedImage				DCC_SetEmbedImage
#define CreateEmoji					DCC_CreateEmoji
#define DeleteEmoji					DCC_DeleteEmoji
#define GetEmojiName				DCC_GetEmojiName
#define CreateReaction				DCC_CreateReaction
#define DeleteMessageReaction		DCC_DeleteMessageReaction

forward OnDiscordCommandPerformed(args[], success);	

forward DCC_OnMessageCreate(DCC_Message:message);
public DCC_OnMessageCreate(DCC_Message:message)
{
    new realMsg[100],
    	bool:IsBot,
    	DCC_Channel:channel,
    	DCC_User:author,
    	DCC_Guild:guild;

    DCC_GetMessageContent(message, realMsg, 100);
    DCC_GetMessageAuthor(message, author);
    DCC_GetMessageChannel(message, channel);
    DCC_GetChannelGuild(channel, guild);
    DCC_IsUserBot(author, IsBot);

    if(!IsBot) //!IsBot will block BOT's message in discord like (Bot A : /ban 1 test")
    {
        new dmsg[10][128];
		explode(dmsg, realMsg, " ", 2);
		new command[24], args[64];
		sscanf(realMsg, "s[24]s[64]", command, args); // Sperate message in COMMAND and arguments.
		if(strfind(command, DISCORD_PREFIX, true) != -1) // Check if command have prefix defined above.
		{
			new funcdc[128];
			strdel(command, 0, 1);
			format(funcdc, sizeof(funcdc), "dc_cmd_%s", command); // Format function.
			
			if(isnull(dmsg[1])) {
				CallLocalFunction("OnDiscordCommandPerformed", "si", realMsg, CallLocalFunction(funcdc, "iiiis", _: channel, _: author, _: message, _: guild, "\1"));
			} else CallLocalFunction("OnDiscordCommandPerformed", "si", realMsg, CallLocalFunction(funcdc, "iiiis", _: channel, _: author, _: message, _: guild, args));
		}
    }

    return 1;
}

stock GetDiscordNameEx(DCC_User:user)
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
