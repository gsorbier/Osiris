#include <string>

#include "imgui/imgui.h"

#include "GUI.h"
#include "Config.h"

void GUI::render() noexcept
{
    renderMenuBar();
    renderAimbotWindow();
    renderGlowWindow();
    renderChamsWindow();
    renderTriggerbotWindow();
    renderMiscWindow();
}

void GUI::renderMenuBar() noexcept
{
    if (ImGui::BeginMainMenuBar()) {
        /* Temporary disable aimbot tab
         *
         * if (ImGui::MenuItem("Aimbot"))
              window.aimbot = true;
        */
        if (ImGui::MenuItem("Glow"))
            window.glow = true;

        if (ImGui::MenuItem("Chams"))
            window.chams = true;

        if (ImGui::MenuItem("Triggerbot"))
            window.triggerbot = true;

        if (ImGui::MenuItem("Misc"))
            window.misc = true;

        if (ImGui::BeginMenu("Config")) {
            if (ImGui::MenuItem("Load"))
                config.load();
            if (ImGui::MenuItem("Save"))
                config.save();
            if (ImGui::MenuItem("Reset"))
                config.reset();
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void GUI::renderAimbotWindow() noexcept
{
    if (window.aimbot) {
        ImGui::SetNextWindowSize(ImVec2(100.0f, 100.0f));
        ImGui::Begin("Aimbot", &window.aimbot, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::End();
    }
}

void GUI::renderGlowWindow() noexcept
{
    if (window.glow) {
        ImGui::SetNextWindowSize(ImVec2(320.0f, 170.0f));
        ImGui::Begin("Glow", &window.glow, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::Columns(2, nullptr, false);
        ImGui::SetColumnOffset(1, 170.0f);
        ImGui::PushItemWidth(80.0f);
        ImGui::Checkbox("Enabled", &config.glow.enabled);
        ImGui::SliderFloat("Thickness", &config.glow.thickness, 0.0f, 1.0f);
        ImGui::SliderFloat("Alpha", &config.glow.alpha, 0.0f, 1.0f);
        ImGui::SliderInt("Style", &config.glow.style, 0, 3);
        ImGui::Checkbox("##Allies", &config.glow.allies);
        ImGui::SameLine(0.0f, 5.0f);
        ImGui::ColorEdit3("Allies", config.glow.alliesColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::NextColumn();
        ImGui::Checkbox("##Weapons", &config.glow.weapons);
        ImGui::SameLine(0.0f, 5.0f);
        ImGui::ColorEdit3("Weapons", config.glow.weaponsColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::Checkbox("##C4", &config.glow.C4);
        ImGui::SameLine(0.0f, 5.0f);
        ImGui::ColorEdit3("C4", config.glow.C4Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::Checkbox("##PlantedC4", &config.glow.plantedC4);
        ImGui::SameLine(0.0f, 5.0f);
        ImGui::ColorEdit3("Planted C4", config.glow.plantedC4Color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::Checkbox("##Chickens", &config.glow.chickens);
        ImGui::SameLine(0.0f, 5.0f);
        ImGui::ColorEdit3("Chickens", config.glow.chickensColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::Checkbox("##Enemies", &config.glow.enemies);
        ImGui::SameLine(0.0f, 5.0f);
        ImGui::ColorEdit3("Enemies", config.glow.enemiesColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::End();
    }
}

void GUI::renderChamsWindow() noexcept
{
    if (window.chams) {
        ImGui::SetNextWindowSize(ImVec2(200.0f, 270.0f));
        ImGui::Begin("Chams", &window.chams, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::PushItemWidth(80.0f);
        ImGui::Checkbox("Enabled", &config.chams.enabled);
        ImGui::SliderFloat("Alpha", &config.chams.alpha, 0.0f, 1.0f);
        ImGui::Checkbox("Enemies only", &config.chams.enemiesOnly);
        ImGui::Checkbox("Visible only", &config.chams.visibleOnly);
        ImGui::ColorEdit3("Visible allies color", config.chams.visibleAlliesColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::ColorEdit3("Occluded allies color", config.chams.occludedAlliesColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::ColorEdit3("Visible enemies color", config.chams.visibleEnemiesColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::ColorEdit3("Occluded enemies color", config.chams.occludedEnemiesColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::Checkbox("Wireframe", &config.chams.wireframe);
        ImGui::End();
    }
}

void GUI::renderTriggerbotWindow() noexcept
{
    if (window.triggerbot) {
        ImGui::SetNextWindowSize(ImVec2(180.0f, 100.0f));
        ImGui::Begin("Triggerbot", &window.triggerbot, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::PushItemWidth(70.0f);
        ImGui::Checkbox("Enabled", &config.triggerbot.enabled);
        ImGui::SliderInt("Shot delay", &config.triggerbot.shotDelay, 0, 250, "%d ms");
        ImGui::End();
    }
}

void GUI::renderMiscWindow() noexcept
{
    if (window.misc) {
        ImGui::SetNextWindowSize(ImVec2(250.0f, 345.0f));
        ImGui::Begin("Misc", &window.misc, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
        ImGui::PushItemWidth(120.0f);
        ImGui::Checkbox("Bunny hop", &config.misc.bunnyHop);
        char buf[16];
        std::strcpy(buf, config.misc.clanTag.c_str());
        ImGui::InputText("Clantag", buf, IM_ARRAYSIZE(buf));
        config.misc.clanTag = buf;
        ImGui::Checkbox("Disable post-processing", &config.misc.disablePostProcessing);
        ImGui::SliderInt("Flash reduction", &config.misc.flashReduction, 0, 100, "%d%%");
        ImGui::Checkbox("Inverse ragdoll gravity", &config.misc.inverseRagdollGravity);
        ImGui::Checkbox("No crouch cooldown", &config.misc.noCrouchCooldown);
        ImGui::Checkbox("No blood", &config.misc.noBlood);
        ImGui::Checkbox("No smoke", &config.misc.noSmoke);
        if (!config.misc.noSmoke)
            ImGui::Checkbox("Wireframe smoke", &config.misc.wireframeSmoke);
        // static const std::string skyboxes[]{ "Default", "cs_baggage_skybox_", "cs_tibet", "embassy", "italy", "jungle", "nukeblank", "office", "sky_cs15_daylight01_hdr", "sky_cs15_daylight02_hdr", "sky_cs15_daylight03_hdr", "sky_cs15_daylight04_hdr", "sky_csgo_cloudy01", "sky_csgo_night_flat", "sky_csgo_night02", "sky_day02_05_hdr", "sky_day02_05", "sky_dust", "sky_l4d_rural02_ldr", "sky_venice", "vertigo_hdr", "vertigo", "vertigoblue_hdr", "vietnam" };
        ImGui::Combo("Skybox", &config.misc.skybox, "Default\0cs_baggage_skybox_\0cs_tibet\0embassy\0italy\0jungle\0nukeblank\0office\0sky_cs15_daylight01_hdr\0sky_cs15_daylight02_hdr\0sky_cs15_daylight03_hdr\0sky_cs15_daylight04_hdr\0sky_csgo_cloudy01\0sky_csgo_night_flat\0sky_csgo_night02\0sky_day02_05_hdr\0sky_day02_05\0sky_dust\0sky_l4d_rural02_ldr\0sky_venice\0vertigo_hdr\0vertigo\0vertigoblue_hdr\0vietnam");
        ImGui::SliderInt("Viewmodel FOV", &config.misc.viewmodelFov, 0, 130);
        ImGui::ColorEdit3("World color", config.misc.worldColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoTooltip);
        ImGui::End();
    }
}
