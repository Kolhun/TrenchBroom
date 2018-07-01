/*
 Copyright (C) 2010-2017 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_ShearObjectsToolPage
#define TrenchBroom_ShearObjectsToolPage

#include "TrenchBroom.h"
#include "VecMath.h"
#include "View/ViewTypes.h"

#include <wx/panel.h>

class wxButton;
class wxTextCtrl;

namespace TrenchBroom {
    namespace View {
        class ShearObjectsTool;
        class SpinControl;
        class SpinControlEvent;
        
        class ShearObjectsToolPage : public wxPanel {
        private:
            MapDocumentWPtr m_document;

            wxTextCtrl* m_scaleFactors;
            wxButton* m_button;
        public:
            ShearObjectsToolPage(wxWindow* parent, MapDocumentWPtr document);
        private:
            void createGui();
            
            void OnUpdateButton(wxUpdateUIEvent& event);
            void OnApply(wxCommandEvent& event);

            static BBox3 scaleBBoxFromCenter(const BBox3& box, const Vec3& scaleFactors);
        };
    }
}

#endif /* defined(TrenchBroom_ShearObjectsToolPage) */