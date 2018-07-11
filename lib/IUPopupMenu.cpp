//

#include "IUPopupMenu.hpp"

void IUPopupMenu::draw()
{
    if (ImGui::BeginPopupContextItem(name.c_str())) {

        IUBaseT<IUMenuBase>::draw();

        ImGui::EndPopup();
    }
};

void IUPopupMenu::openPopup()
{
    ImGui::OpenPopup(name.c_str());
}
