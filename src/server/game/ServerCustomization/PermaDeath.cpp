#include "ServerCustomization/PermaDeath.h"

using namespace JulMan;

void PermaDeath::OnPlayerJustDied(Player *player) {
    if (!m_permaDeath) return;

    if (player->IsGameMaster()) return;

    WorldSession *session = GetPlayerSession(player);

    uint32 guid = session->GetGuidLow();

    std::stringstream query;
    query << "INSERT INTO character_banned (guid, bannedby, banreason, active) VALUES (" << guid
          << ", 'PermaDeath', 'Death', 1)";
    CharacterDatabase.Execute(query.str());

    player->SaveToDB(false, true);
    session->KickPlayer();
}
