//Created Entirely By https://github.com/ttvtempest17
//M.I.T Licence
//0.0.1 version

///Class for the theme editior
///Construct it after ImGui Context Creation
class theme {
private:
    float TextColor[4] = { 0 };
    float TextDisabled[4] = { 0 };
    float TabColor[4] = { 0 };
    float TabHovered[4] = { 0 };
    float TabActive[4] = { 0 };
    float WindowBackground[4] = { 0 };
    float PopupBackground[4] = { 0 };
    float BorderColor[4] = { 0 };
    float BorderShadow[4] = { 0 };
    float FrameBackground[4] = { 0 };
    float FrameBackgroundHovered[4] = { 0 };
    float FrameBackgroundActive[4] = { 0 };
    float TitleBackground[4] = { 0 };
    float TitleBackgroundCollapsed[4] = { 0 };
    float TitleBackgroundActive[4] = { 0 };
    float MenuBarBackground[4] = { 0 };
    float ScrollbarBackground[4] = { 0 };
    float ScrollbarGrab[4] = { 0 };
    float ScrollbarGrabHover[4] = { 0 };
    float ScrollbarGrabActive[4] = { 0 };
    float CheckMark[4] = { 0 };
    float SliderGrab[4] = { 0 };
    float SliderGrabActive[4] = { 0 };
    float Button[4] = { 0 };
    float ButtonHovered[4] = { 0 };
    float ButtonActive[4] = { 0 };
    float Header[4] = { 0 };
    float HeaderHovered[4] = { 0 };
    float HeaderActive[4] = { 0 };
    float ResizeGrip[4] = { 0 };
    float ResizeGripHovered[4] = { 0 };
    float ResizeGripActive[4] = { 0 };
    float PlotLines[4] = { 0 };
    float PlotLinesHovered[4] = { 0 };
    float PlotHistogram[4] = { 0 };
    float PlotHistogramHovered[4] = { 0 };
    float TextSelectedBackgroud[4] = { 0 };
    float IndentSpacing = 25.0f;
    float ScrollbarSize = 15.0f;
    float ScrollbarRounding = 9.0f;
    float GrabMinSize = 5.0f;
    float GrabRounding = 3.0f;
    bool livePreview = true;
    int setallcur = 0;
    std::string fileName;
    std::ofstream themeExport;
    ImVec4 TextColorV;
    time_t now = time(0);
    char* dt;

public: 
    ///Creates a theme editor for ImGui
    ///Requires valid ImGui Context
    ///Doesn't care about rendering api
    void ThemeEditor() {

        style = &ImGui::GetStyle();
        TextColorV = ImVec4(TextColor[0], TextColor[1], TextColor[2], TextColor[3]);
        ImGui::Text("Colors");
        ImGui::ColorEdit4("Text", TextColor);
        ImGui::ColorEdit4("Text Disabled", TextDisabled);
        ImGui::ColorEdit4("Tab", TabColor);
        ImGui::ColorEdit4("Tab Active", TabActive);
        ImGui::ColorEdit4("Window Background", WindowBackground);
        ImGui::ColorEdit4("Popup Background", PopupBackground);
        ImGui::ColorEdit4("Border", BorderColor);
        ImGui::ColorEdit4("Border Shadow", BorderShadow);
        ImGui::ColorEdit4("Frame Background", FrameBackground);
        ImGui::ColorEdit4("Frame Background Hovered", FrameBackgroundHovered);
        ImGui::ColorEdit4("Frame Background Active", FrameBackgroundActive);
        ImGui::ColorEdit4("Title Background", TitleBackground);
        ImGui::ColorEdit4("Title Background Collapsed", TitleBackgroundCollapsed);
        ImGui::ColorEdit4("Title Background Active", TitleBackgroundActive);
        ImGui::ColorEdit4("Menu Bar Background", MenuBarBackground);
        ImGui::ColorEdit4("Scrollbar Background", ScrollbarBackground);
        ImGui::ColorEdit4("Scrollbar Grab", ScrollbarGrab);
        ImGui::ColorEdit4("Scrollbar Grab Hover", ScrollbarGrabHover);
        ImGui::ColorEdit4("Scrollbar Grab Active", ScrollbarGrabActive);
        ImGui::ColorEdit4("Checkmark", CheckMark);
        ImGui::ColorEdit4("Slider Grab", SliderGrab);
        ImGui::ColorEdit4("Slider Grab Active", SliderGrabActive);
        ImGui::ColorEdit4("Button", Button);
        ImGui::ColorEdit4("Button Hovered", ButtonHovered);
        ImGui::ColorEdit4("Button Active", ButtonActive);
        ImGui::ColorEdit4("Header", Header);
        ImGui::ColorEdit4("Header Hovered", HeaderHovered);
        ImGui::ColorEdit4("Header Active", HeaderActive);
        ImGui::ColorEdit4("Resize Grip", ResizeGrip);
        ImGui::ColorEdit4("Resize Grip Hovered", ResizeGripHovered);
        ImGui::ColorEdit4("Resize Grip Active", ResizeGripActive);
        ImGui::ColorEdit4("Plot Lines", PlotLines);
        ImGui::ColorEdit4("Plot Lines Hovered", PlotLinesHovered);
        ImGui::ColorEdit4("Plot Histogram", PlotHistogram);
        ImGui::ColorEdit4("Plot Histogram Hovered", PlotHistogramHovered);
        ImGui::ColorEdit4("Text Selected Background", TextSelectedBackgroud);

        ImGui::Text("Spacing");
        ImGui::SliderFloat("Scroll Bar Size", &ScrollbarSize, 1.0f, 20.0f, NULL, ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoRoundToFormat);
        ImGui::SliderFloat("ScrollbarRounding", &ScrollbarRounding, 0.0f, 15.0f, NULL, ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoRoundToFormat);
        ImGui::SliderFloat("Indent Spacing", &IndentSpacing, 1.0f, 50.0f, NULL, ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoRoundToFormat);
        ImGui::SliderFloat("Grab Min Size", &GrabMinSize, 1.0f, 30.0f, NULL, ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoRoundToFormat);
        ImGui::SliderFloat("Grab Rounding", &GrabRounding, 1.0f, 15.0f, NULL, ImGuiSliderFlags_Logarithmic | ImGuiSliderFlags_NoRoundToFormat);

        if (ImGui::Button("Apply")) {
            style->Colors[ImGuiCol_Text] = TextColorV;
            style->Colors[ImGuiCol_TextDisabled] = ImVec4(TextDisabled[0], TextDisabled[1], TextDisabled[2], TextDisabled[3]);
            style->Colors[ImGuiCol_Tab] = ImVec4(TabColor[0], TabColor[1], TabColor[2], TabColor[3]);
            style->Colors[ImGuiCol_TabHovered] = ImVec4(TabHovered[0], TabHovered[1], TabHovered[2], TabHovered[3]);
            style->Colors[ImGuiCol_TabActive] = ImVec4(TabActive[0], TabActive[1], TabActive[2], TabActive[3]);
            style->Colors[ImGuiCol_WindowBg] = ImVec4(WindowBackground[0], WindowBackground[1], WindowBackground[2], WindowBackground[3]);
            style->Colors[ImGuiCol_PopupBg] = ImVec4(PopupBackground[0], PopupBackground[1], PopupBackground[2], PopupBackground[3]);
            style->Colors[ImGuiCol_Border] = ImVec4(BorderColor[0], BorderColor[1], BorderColor[2], BorderColor[3]);
            style->Colors[ImGuiCol_BorderShadow] = ImVec4(BorderShadow[0], BorderShadow[1], BorderShadow[2], BorderShadow[3]);
            style->Colors[ImGuiCol_FrameBg] = ImVec4(FrameBackground[0], FrameBackground[1], FrameBackground[2], FrameBackground[3]);
            style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(FrameBackgroundHovered[0], FrameBackgroundHovered[1], FrameBackgroundHovered[2], FrameBackgroundHovered[3]);
            style->Colors[ImGuiCol_FrameBgActive] = ImVec4(FrameBackgroundActive[0], FrameBackgroundActive[1], FrameBackgroundActive[2], FrameBackgroundActive[3]);
            style->Colors[ImGuiCol_TitleBg] = ImVec4(TitleBackground[0], TitleBackground[1], TitleBackground[2], TitleBackground[3]);
            style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(TitleBackgroundCollapsed[0], TitleBackgroundCollapsed[1], TitleBackgroundCollapsed[2], TitleBackgroundCollapsed[3]);
            style->Colors[ImGuiCol_TitleBgActive] = ImVec4(TitleBackgroundActive[0], TitleBackgroundActive[1], TitleBackgroundActive[2], TitleBackgroundActive[3]);
            style->Colors[ImGuiCol_MenuBarBg] = ImVec4(MenuBarBackground[0], MenuBarBackground[1], MenuBarBackground[2], MenuBarBackground[3]);
            style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(ScrollbarBackground[0], ScrollbarBackground[1], ScrollbarBackground[2], ScrollbarBackground[3]);
            style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(ScrollbarGrab[0], ScrollbarGrab[1], ScrollbarGrab[2], ScrollbarGrab[3]);
            style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(ScrollbarGrabHover[0], ScrollbarGrabHover[1], ScrollbarGrabHover[2], ScrollbarGrabHover[3]);
            style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(ScrollbarGrabActive[0], ScrollbarGrabActive[1], ScrollbarGrabActive[2], ScrollbarGrabActive[3]);
            style->Colors[ImGuiCol_CheckMark] = ImVec4(CheckMark[0], CheckMark[1], CheckMark[2], CheckMark[3]);
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(SliderGrab[0], SliderGrab[1], SliderGrab[2], SliderGrab[3]);
            style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(SliderGrabActive[0], SliderGrabActive[1], SliderGrabActive[2], SliderGrabActive[3]);
            style->Colors[ImGuiCol_Button] = ImVec4(Button[0], Button[1], Button[2], Button[3]);
            style->Colors[ImGuiCol_ButtonHovered] = ImVec4(ButtonHovered[0], ButtonHovered[1], ButtonHovered[2], ButtonHovered[3]);
            style->Colors[ImGuiCol_ButtonActive] = ImVec4(ButtonActive[0], ButtonActive[1], ButtonActive[2], ButtonActive[3]);
            style->Colors[ImGuiCol_Header] = ImVec4(Header[0], Header[1], Header[2], Header[3]);
            style->Colors[ImGuiCol_HeaderHovered] = ImVec4(HeaderHovered[0], HeaderHovered[1], HeaderHovered[2], HeaderHovered[3]);
            style->Colors[ImGuiCol_HeaderActive] = ImVec4(HeaderActive[0], HeaderActive[1], HeaderActive[2], HeaderActive[3]);
            style->Colors[ImGuiCol_ResizeGrip] = ImVec4(ResizeGrip[0], ResizeGrip[1], ResizeGrip[2], ResizeGrip[3]);
            style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(ResizeGripHovered[0], ResizeGripHovered[1], ResizeGripHovered[2], ResizeGripHovered[3]);
            style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(ResizeGripActive[0], ResizeGripActive[1], ResizeGripActive[2], ResizeGripActive[3]);
            style->Colors[ImGuiCol_PlotLines] = ImVec4(PlotLines[0], PlotLines[1], PlotLines[2], PlotLines[3]);
            style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(PlotLinesHovered[0], PlotLinesHovered[1], PlotLinesHovered[2], PlotLinesHovered[3]);
            style->Colors[ImGuiCol_PlotHistogram] = ImVec4(PlotHistogram[0], PlotHistogram[1], PlotHistogram[2], PlotHistogram[3]);
            style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(PlotHistogramHovered[0], PlotHistogramHovered[1], PlotHistogramHovered[2], PlotHistogramHovered[3]);
            style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(TextSelectedBackgroud[0], TextSelectedBackgroud[1], TextSelectedBackgroud[2], TextSelectedBackgroud[3]);

            style->ScrollbarSize = ScrollbarSize;
            style->ScrollbarRounding = ScrollbarRounding;
            style->IndentSpacing = IndentSpacing;
            style->GrabMinSize = GrabMinSize;
            style->GrabRounding = GrabRounding;
        }
        ImGui::SameLine();
        if (ImGui::Button("Set All Current")) {
            setallcur++;
            ScrollbarSize = style->ScrollbarSize;
            ScrollbarRounding = style->ScrollbarRounding;
            IndentSpacing = style->IndentSpacing;
            GrabMinSize = style->GrabMinSize;
            GrabRounding = style->GrabRounding;

            TextColor[0] = style->Colors[ImGuiCol_Text].x;
            TextColor[1] = style->Colors[ImGuiCol_Text].y;
            TextColor[2] = style->Colors[ImGuiCol_Text].z;
            TextColor[3] = style->Colors[ImGuiCol_Text].w;

            TextDisabled[0] = style->Colors[ImGuiCol_TextDisabled].x;
            TextDisabled[1] = style->Colors[ImGuiCol_TextDisabled].y;
            TextDisabled[2] = style->Colors[ImGuiCol_TextDisabled].z;
            TextDisabled[3] = style->Colors[ImGuiCol_TextDisabled].w;

            TabColor[0] = style->Colors[ImGuiCol_Tab].x;
            TabColor[1] = style->Colors[ImGuiCol_Tab].y;
            TabColor[2] = style->Colors[ImGuiCol_Tab].z;
            TabColor[3] = style->Colors[ImGuiCol_Tab].w;

            TabHovered[0] = style->Colors[ImGuiCol_TabHovered].x;
            TabHovered[1] = style->Colors[ImGuiCol_TabHovered].y;
            TabHovered[2] = style->Colors[ImGuiCol_TabHovered].z;
            TabHovered[3] = style->Colors[ImGuiCol_TabHovered].w;

            TabActive[0] = style->Colors[ImGuiCol_TabActive].x;
            TabActive[1] = style->Colors[ImGuiCol_TabActive].y;
            TabActive[2] = style->Colors[ImGuiCol_TabActive].z;
            TabActive[3] = style->Colors[ImGuiCol_TabActive].w;

            WindowBackground[0] = style->Colors[ImGuiCol_WindowBg].x;
            WindowBackground[1] = style->Colors[ImGuiCol_WindowBg].y;
            WindowBackground[2] = style->Colors[ImGuiCol_WindowBg].z;
            WindowBackground[3] = style->Colors[ImGuiCol_WindowBg].w;

            PopupBackground[0] = style->Colors[ImGuiCol_PopupBg].x;
            PopupBackground[1] = style->Colors[ImGuiCol_PopupBg].y;
            PopupBackground[2] = style->Colors[ImGuiCol_PopupBg].z;
            PopupBackground[3] = style->Colors[ImGuiCol_PopupBg].w;


            BorderColor[0] = style->Colors[ImGuiCol_Border].x;
            BorderColor[1] = style->Colors[ImGuiCol_Border].y;
            BorderColor[2] = style->Colors[ImGuiCol_Border].z;
            BorderColor[3] = style->Colors[ImGuiCol_Border].w;


            BorderShadow[0] = style->Colors[ImGuiCol_BorderShadow].x;
            BorderShadow[1] = style->Colors[ImGuiCol_BorderShadow].y;
            BorderShadow[2] = style->Colors[ImGuiCol_BorderShadow].z;
            BorderShadow[3] = style->Colors[ImGuiCol_BorderShadow].w;

            FrameBackground[0] = style->Colors[ImGuiCol_FrameBg].x;
            FrameBackground[1] = style->Colors[ImGuiCol_FrameBg].y;
            FrameBackground[2] = style->Colors[ImGuiCol_FrameBg].z;
            FrameBackground[3] = style->Colors[ImGuiCol_FrameBg].w;

            FrameBackgroundHovered[0] = style->Colors[ImGuiCol_FrameBgHovered].x;
            FrameBackgroundHovered[0] = style->Colors[ImGuiCol_FrameBgHovered].y;
            FrameBackgroundHovered[0] = style->Colors[ImGuiCol_FrameBgHovered].z;
            FrameBackgroundHovered[0] = style->Colors[ImGuiCol_FrameBgHovered].w;

            FrameBackgroundActive[0] = style->Colors[ImGuiCol_FrameBgActive].x;
            FrameBackgroundActive[1] = style->Colors[ImGuiCol_FrameBgActive].y;
            FrameBackgroundActive[2] = style->Colors[ImGuiCol_FrameBgActive].z;
            FrameBackgroundActive[3] = style->Colors[ImGuiCol_FrameBgActive].w;

            TitleBackground[0] = style->Colors[ImGuiCol_TitleBg].x;
            TitleBackground[1] = style->Colors[ImGuiCol_TitleBg].y;
            TitleBackground[2] = style->Colors[ImGuiCol_TitleBg].z;
            TitleBackground[3] = style->Colors[ImGuiCol_TitleBg].w;

            TitleBackgroundCollapsed[0] = style->Colors[ImGuiCol_TitleBgCollapsed].x;
            TitleBackgroundCollapsed[1] = style->Colors[ImGuiCol_TitleBgCollapsed].y;
            TitleBackgroundCollapsed[2] = style->Colors[ImGuiCol_TitleBgCollapsed].z;
            TitleBackgroundCollapsed[3] = style->Colors[ImGuiCol_TitleBgCollapsed].w;

            TitleBackgroundActive[0] = style->Colors[ImGuiCol_TitleBgActive].x;
            TitleBackgroundActive[1] = style->Colors[ImGuiCol_TitleBgActive].y;
            TitleBackgroundActive[2] = style->Colors[ImGuiCol_TitleBgActive].z;
            TitleBackgroundActive[3] = style->Colors[ImGuiCol_TitleBgActive].w;

            MenuBarBackground[0] = style->Colors[ImGuiCol_MenuBarBg].x;
            MenuBarBackground[1] = style->Colors[ImGuiCol_MenuBarBg].y;
            MenuBarBackground[2] = style->Colors[ImGuiCol_MenuBarBg].z;
            MenuBarBackground[3] = style->Colors[ImGuiCol_MenuBarBg].w;

            ScrollbarBackground[0] = style->Colors[ImGuiCol_ScrollbarBg].x;
            ScrollbarBackground[1] = style->Colors[ImGuiCol_ScrollbarBg].y;
            ScrollbarBackground[2] = style->Colors[ImGuiCol_ScrollbarBg].z;
            ScrollbarBackground[3] = style->Colors[ImGuiCol_ScrollbarBg].w;

            ScrollbarGrab[0] = style->Colors[ImGuiCol_ScrollbarGrab].x;
            ScrollbarGrab[1] = style->Colors[ImGuiCol_ScrollbarGrab].y;
            ScrollbarGrab[2] = style->Colors[ImGuiCol_ScrollbarGrab].z;
            ScrollbarGrab[3] = style->Colors[ImGuiCol_ScrollbarGrab].w;

            ScrollbarGrabHover[0] = style->Colors[ImGuiCol_ScrollbarGrabHovered].x;
            ScrollbarGrabHover[1] = style->Colors[ImGuiCol_ScrollbarGrabHovered].y;
            ScrollbarGrabHover[2] = style->Colors[ImGuiCol_ScrollbarGrabHovered].z;
            ScrollbarGrabHover[3] = style->Colors[ImGuiCol_ScrollbarGrabHovered].w;

            ScrollbarGrabActive[0] = style->Colors[ImGuiCol_ScrollbarGrabActive].x;
            ScrollbarGrabActive[1] = style->Colors[ImGuiCol_ScrollbarGrabActive].y;
            ScrollbarGrabActive[2] = style->Colors[ImGuiCol_ScrollbarGrabActive].z;
            ScrollbarGrabActive[3] = style->Colors[ImGuiCol_ScrollbarGrabActive].w;

            CheckMark[0] = style->Colors[ImGuiCol_CheckMark].x;
            CheckMark[1] = style->Colors[ImGuiCol_CheckMark].y;
            CheckMark[2] = style->Colors[ImGuiCol_CheckMark].z;
            CheckMark[3] = style->Colors[ImGuiCol_CheckMark].w;

            SliderGrab[0] = style->Colors[ImGuiCol_SliderGrab].x;
            SliderGrab[1] = style->Colors[ImGuiCol_SliderGrab].y;
            SliderGrab[2] = style->Colors[ImGuiCol_SliderGrab].z;
            SliderGrab[3] = style->Colors[ImGuiCol_SliderGrab].w;

            SliderGrabActive[0] = style->Colors[ImGuiCol_SliderGrabActive].x;
            SliderGrabActive[1] = style->Colors[ImGuiCol_SliderGrabActive].y;
            SliderGrabActive[2] = style->Colors[ImGuiCol_SliderGrabActive].z;
            SliderGrabActive[3] = style->Colors[ImGuiCol_SliderGrabActive].w;

            Button[0] = style->Colors[ImGuiCol_Button].x;
            Button[1] = style->Colors[ImGuiCol_Button].y;
            Button[2] = style->Colors[ImGuiCol_Button].z;
            Button[3] = style->Colors[ImGuiCol_Button].w;

            ButtonHovered[0] = style->Colors[ImGuiCol_ButtonHovered].x;
            ButtonHovered[1] = style->Colors[ImGuiCol_ButtonHovered].y;
            ButtonHovered[2] = style->Colors[ImGuiCol_ButtonHovered].z;
            ButtonHovered[3] = style->Colors[ImGuiCol_ButtonHovered].w;

            Header[0] = style->Colors[ImGuiCol_Header].x;
            Header[1] = style->Colors[ImGuiCol_Header].y;
            Header[2] = style->Colors[ImGuiCol_Header].z;
            Header[3] = style->Colors[ImGuiCol_Header].w;

            HeaderHovered[0] = style->Colors[ImGuiCol_HeaderHovered].x;
            HeaderHovered[1] = style->Colors[ImGuiCol_HeaderHovered].y;
            HeaderHovered[2] = style->Colors[ImGuiCol_HeaderHovered].z;
            HeaderHovered[3] = style->Colors[ImGuiCol_HeaderHovered].w;

            HeaderActive[0] = style->Colors[ImGuiCol_HeaderActive].x;
            HeaderActive[1] = style->Colors[ImGuiCol_HeaderActive].y;
            HeaderActive[2] = style->Colors[ImGuiCol_HeaderActive].z;
            HeaderActive[3] = style->Colors[ImGuiCol_HeaderActive].w;

            ResizeGrip[0] = style->Colors[ImGuiCol_ResizeGrip].x;
            ResizeGrip[1] = style->Colors[ImGuiCol_ResizeGrip].y;
            ResizeGrip[2] = style->Colors[ImGuiCol_ResizeGrip].z;
            ResizeGrip[3] = style->Colors[ImGuiCol_ResizeGrip].w;

            ResizeGripHovered[0] = style->Colors[ImGuiCol_ResizeGripHovered].x;
            ResizeGripHovered[1] = style->Colors[ImGuiCol_ResizeGripHovered].y;
            ResizeGripHovered[2] = style->Colors[ImGuiCol_ResizeGripHovered].z;
            ResizeGripHovered[3] = style->Colors[ImGuiCol_ResizeGripHovered].w;

            ResizeGripActive[0] = style->Colors[ImGuiCol_ResizeGripActive].x;
            ResizeGripActive[1] = style->Colors[ImGuiCol_ResizeGripActive].y;
            ResizeGripActive[2] = style->Colors[ImGuiCol_ResizeGripActive].z;
            ResizeGripActive[3] = style->Colors[ImGuiCol_ResizeGripActive].w;

            PlotLines[0] = style->Colors[ImGuiCol_PlotLines].x;
            PlotLines[1] = style->Colors[ImGuiCol_PlotLines].y;
            PlotLines[2] = style->Colors[ImGuiCol_PlotLines].z;
            PlotLines[3] = style->Colors[ImGuiCol_PlotLines].w;

            PlotLinesHovered[0] = style->Colors[ImGuiCol_PlotLinesHovered].x;
            PlotLinesHovered[1] = style->Colors[ImGuiCol_PlotLinesHovered].y;
            PlotLinesHovered[2] = style->Colors[ImGuiCol_PlotLinesHovered].z;
            PlotLinesHovered[3] = style->Colors[ImGuiCol_PlotLinesHovered].w;

            PlotHistogram[0] = style->Colors[ImGuiCol_PlotHistogram].x;
            PlotHistogram[1] = style->Colors[ImGuiCol_PlotHistogram].y;
            PlotHistogram[2] = style->Colors[ImGuiCol_PlotHistogram].z;
            PlotHistogram[3] = style->Colors[ImGuiCol_PlotHistogram].w;

            PlotHistogramHovered[0] = style->Colors[ImGuiCol_PlotHistogramHovered].x;
            PlotHistogramHovered[1] = style->Colors[ImGuiCol_PlotHistogramHovered].y;
            PlotHistogramHovered[2] = style->Colors[ImGuiCol_PlotHistogramHovered].z;
            PlotHistogramHovered[3] = style->Colors[ImGuiCol_PlotHistogramHovered].w;

            TextSelectedBackgroud[0] = style->Colors[ImGuiCol_TextSelectedBg].x;
            TextSelectedBackgroud[1] = style->Colors[ImGuiCol_TextSelectedBg].y;
            TextSelectedBackgroud[2] = style->Colors[ImGuiCol_TextSelectedBg].z;
            TextSelectedBackgroud[3] = style->Colors[ImGuiCol_TextSelectedBg].w;

        }

        if (ImGui::IsItemHovered()) {
            ImGui::SetTooltip(
                "This sets all color editors to the current\n"
                "Applied themes values"
            );
        }
        ImGui::SameLine();
        if (ImGui::Button("Export")) {
            dt = ctime(&now);

            themeExport.open(fileName + ".h");
            themeExport << "//Generated by DarkDays.exe\n";
            themeExport << "//Licenced Under GPL 3.0\n";
            themeExport << "//This should be called after you create your ImGui Context\n";
            themeExport << "//Generated on " << dt << "\n\n";
            themeExport << "///This is the theme you generated hope you enjoy<3\n";
            themeExport << "void generatedTheme() {\n";
            themeExport << "    ImGuiStyle* style = &ImGui::GetStyle();\n";
            themeExport << "    style->Colors[ImGuiCol_Text] = ImVec4(" << TextColor[0] << ',' << TextColor[1] << ',' << TextColor[2] << ',' << TextColor[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TextDisabled] = ImVec4(" << TextDisabled[0] << ',' << TextDisabled[1] << ',' << TextDisabled[2] << ',' << TextDisabled[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_Tab] = ImVec4(" << TabColor[0] << ',' << TabColor[1] << ',' << TabColor[2] << ',' << TabColor[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TabHovered] = ImVec4(" << TabHovered[0] << ',' << TabHovered[1] << ',' << TabHovered[2] << ',' << TabHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TabActive] = ImVec4(" << TabActive[0] << ',' << TabActive[1] << ',' << TabActive[2] << ',' << TabActive[3] << "); \n";
            themeExport << "    style->Colors[ImGuiCol_WindowBg] = ImVec4(" << WindowBackground[0] << ',' << WindowBackground[1] << ',' << WindowBackground[2] << ',' << WindowBackground[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_PopupBg] = ImVec4(" << PopupBackground[0] << ',' << PopupBackground[1] << ',' << PopupBackground[2] << ',' << PopupBackground[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_Border] = ImVec4(" << BorderColor[0] << ',' << BorderColor[1] << ',' << BorderColor[2] << ',' << BorderColor[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_BorderShadow] = ImVec4(" << BorderShadow[0] << ',' << BorderShadow[1] << ',' << BorderShadow[2] << ',' << BorderShadow[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_FrameBg] = ImVec4(" << FrameBackground[0] << ',' << FrameBackground[1] << ',' << FrameBackground[2] << ',' << FrameBackground[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(" << FrameBackgroundHovered[0] << ',' << FrameBackgroundHovered[1] << ',' << FrameBackgroundHovered[2] << ',' << FrameBackgroundHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_FrameBgActive] = ImVec4(" << FrameBackgroundActive[0] << ',' << FrameBackgroundActive[1] << ',' << FrameBackgroundActive[2] << ',' << FrameBackgroundActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TitleBg] = ImVec4(" << TitleBackground[0] << ',' << TitleBackground[1] << ',' << TitleBackground[2] << ',' << TitleBackground[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(" << TitleBackgroundCollapsed[0] << ',' << TitleBackgroundCollapsed[1] << ',' << TitleBackgroundCollapsed[2] << ',' << TitleBackgroundCollapsed[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TitleBgActive] = ImVec4(" << TitleBackgroundActive[0] << ',' << TitleBackgroundActive[1] << ',' << TitleBackgroundActive[2] << ',' << TitleBackgroundActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_MenuBarBg] = ImVec4(" << MenuBarBackground[0] << ',' << MenuBarBackground[1] << ',' << MenuBarBackground[2] << ',' << MenuBarBackground[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(" << ScrollbarBackground[0] << ',' << ScrollbarBackground[1] << ',' << ScrollbarBackground[2] << ',' << ScrollbarBackground[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(" << ScrollbarGrab[0] << ',' << ScrollbarGrab[1] << ',' << ScrollbarGrab[2] << ',' << ScrollbarGrab[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(" << ScrollbarGrabHover[0] << ',' << ScrollbarGrabHover[1] << ',' << ScrollbarGrabHover[2] << ',' << ScrollbarGrabHover[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(" << ScrollbarGrabActive[0] << ',' << ScrollbarGrabActive[1] << ',' << ScrollbarGrabActive[2] << ',' << ScrollbarGrabActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_CheckMark] = ImVec4(" << CheckMark[0] << ',' << CheckMark[1] << ',' << CheckMark[2] << ',' << CheckMark[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_SliderGrab] = ImVec4(" << SliderGrab[0] << ',' << SliderGrab[1] << ',' << SliderGrab[2] << ',' << SliderGrab[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(" << SliderGrabActive[0] << ',' << SliderGrabActive[1] << ',' << SliderGrabActive[2] << ',' << SliderGrabActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_Button] = ImVec4(" << Button[0] << ',' << Button[1] << ',' << Button[2] << ',' << Button[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ButtonHovered] = ImVec4(" << ButtonHovered[0] << ',' << ButtonHovered[1] << ',' << ButtonHovered[2] << ',' << ButtonHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ButtonActive] = ImVec4(" << ButtonActive[0] << ',' << ButtonActive[1] << ',' << ButtonActive[2] << ',' << ButtonActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_Header] = ImVec4(" << Header[0] << ',' << Header[1] << ',' << Header[2] << ',' << Header[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_HeaderHovered] = ImVec4(" << HeaderHovered[0] << ',' << HeaderHovered[1] << ',' << HeaderHovered[2] << ',' << HeaderHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_HeaderActive] = ImVec4(" << HeaderActive[0] << ',' << HeaderActive[1] << ',' << HeaderActive[2] << ',' << HeaderActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ResizeGrip] = ImVec4(" << ResizeGrip[0] << ',' << ResizeGrip[1] << ',' << ResizeGrip[2] << ',' << ResizeGrip[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(" << ResizeGripHovered[0] << ',' << ResizeGripHovered[1] << ',' << ResizeGripHovered[2] << ',' << ResizeGripHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(" << ResizeGripActive[0] << ',' << ResizeGripActive[1] << ',' << ResizeGripActive[2] << ',' << ResizeGripActive[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_PlotLines] = ImVec4(" << PlotLines[0] << ',' << PlotLines[1] << ',' << PlotLines[2] << ',' << PlotLines[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(" << PlotLinesHovered[0] << ',' << PlotLinesHovered[1] << ',' << PlotLinesHovered[2] << ',' << PlotLinesHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_PlotHistogram] = ImVec4(" << PlotHistogram[0] << ',' << PlotHistogram[1] << ',' << PlotHistogram[2] << ',' << PlotHistogram[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(" << PlotHistogramHovered[0] << ',' << PlotHistogramHovered[1] << ',' << PlotHistogramHovered[2] << ',' << PlotHistogramHovered[3] << ");\n";
            themeExport << "    style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(" << TextSelectedBackgroud[0] << ',' << TextSelectedBackgroud[1] << ',' << TextSelectedBackgroud[2] << ',' << TextSelectedBackgroud[3] << ");\n";
            themeExport << "    style->ScrollbarSize = " << ScrollbarSize << ";\n";
            themeExport << "    style->ScrollbarRounding = " << ScrollbarRounding << ";\n";
            themeExport << "    style->IndentSpacing = " << IndentSpacing << ";\n";
            themeExport << "    style->GrabMinSize = " << GrabMinSize << ";\n";
            themeExport << "    style->GrabRounding = " << GrabRounding << ";\n";
            themeExport << "}\n";
            themeExport.close();
        }
        if (ImGui::IsItemHovered()) {
            ImGui::SetTooltip(
                "This exports all theme settings to a header file.\n"
                "Every theme exported is assumed to be licenced under GPL 3.0\n"
                "Open Source forever and always <3\n"
            );
        }
        ImGui::SetNextItemWidth(210.0f);
        ImGui::InputTextWithHint("##File Name", "Generated file Name.h", &fileName);

    }
};