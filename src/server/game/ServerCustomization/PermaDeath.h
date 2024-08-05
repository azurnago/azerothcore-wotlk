#pragma once

#include "Defines.h"
#include "ScriptsRegistry.h"

#include "Scripting/ScriptDefines/PlayerScript.h"
#include "Entities/Player/Player.h"
#include "World/World.h"
#include "Configuration/Config.h"

namespace JulMan {
    static bool m_permaDeath = true;

    class PermaDeath : public PlayerScript {
    private:
    public:
        inline PermaDeath() : PlayerScript("PermaDeath") {
            m_permaDeath = ConfigMgr::instance()->GetOption(JULMAN_PERMADEATH_CONFIG_KEY, true);
        };

        ~PermaDeath() override = default;

        void OnPlayerJustDied(Player *) override;

        inline static PermaDeath *instance() {
            static PermaDeath instance;
            return &instance;
        }
    };

    inline WorldSession *GetPlayerSession(Player *player) {
        return player->GetSession();
    }
}
