//
// Created by toxicoverflow on 23.02.17.
//

#include "main.hpp"

#ifndef MICROWAVE_SKINCHANGER_H
#define MICROWAVE_SKINCHANGER_H

class cSkin{
public:
    
    cSkin(){}
    
    cSkin(int paintkit, int seed, int itemDefinition, int stattrack, char* szName, float flWear) :
            Paintkit(paintkit), Seed(seed), ItemDefinition(itemDefinition), StatTrack(stattrack), name(szName), Wear(flWear){}

    int Paintkit = 0;
    int Seed = 0;
    int ItemDefinition = 0;
    int StatTrack = -1;
    char* name = nullptr;
    float Wear = 0.0001f;
};

class cSkinchanger {
public:
    static std::unordered_map<int, cSkin> SkinList;

    std::unordered_map<int, std::string> KnifeToModelMatrix = std::unordered_map<int, std::string>({
                    {WEAPON_KNIFE_BAYONET, "models/weapons/v_knife_bayonet.mdl"}, // Bayonet Knife
                    {WEAPON_KNIFE_FLIP, "models/weapons/v_knife_flip.mdl"}, // Flip Knife
                    {WEAPON_KNIFE_GUT, "models/weapons/v_knife_gut.mdl"}, // Gut Knife
                    {WEAPON_KNIFE_KARAMBIT, "models/weapons/v_knife_karam.mdl"}, // Karambit Knife 
                    {WEAPON_KNIFE_M9_BAYONET, "models/weapons/v_knife_m9_bay.mdl"}, // M9 Knife
                    {WEAPON_KNIFE_TACTICAL, "models/weapons/v_knife_tactical.mdl"}, // Huntsman Knife
                    {WEAPON_KNIFE_FALCHION, "models/weapons/v_knife_falchion_advanced.mdl"}, // Falchion Knife (Animation Broken)
                    {WEAPON_KNIFE_SURVIVAL_BOWIE, "models/weapons/v_knife_survival_bowie.mdl"}, // Bowie Knife (Animation Broken)
                    {WEAPON_KNIFE_BUTTERFLY, "models/weapons/v_knife_butterfly.mdl"}, // Butterfly Knife (Animation Broken)
                    {WEAPON_KNIFE_PUSH, "models/weapons/v_knife_push.mdl"} // Shadow Daggers (Animation Broken)
            });


    int Knife = WEAPON_KNIFE_M9_BAYONET;
    int KnifeT = WEAPON_KNIFE_TACTICAL;

    void FireEventClientSide(IGameEvent* event);
    static std::unordered_map<int, const char*> ModelList;

    void FindModels();
    void Init();
    void ForceSkins();
    void FrameStageNotify(ClientFrameStage_t stage);

    C_BaseEntity* pLocalPlayer = nullptr;

    bool bInit = false;
};

extern cSkinchanger* skinchanger;


#endif //MICROWAVE_SKINCHANGER_H
