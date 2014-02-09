/*
 Copyright (C) 2010-2014 Kristian Duske
 
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

#include "ViewUtils.h"

#include "Exceptions.h"
#include "Logger.h"
#include "Assets/EntityModelManager.h"
#include "Assets/ModelDefinition.h"

namespace TrenchBroom {
    namespace View {
        Assets::EntityModel* safeGetModel(Assets::EntityModelManager& manager, const Assets::ModelSpecification& spec, Logger& logger) {
            try {
                return manager.model(spec.path);
            } catch (const GameException& e) {
                logger.error(String(e.what()));
                return NULL;
            }
        }

        void combineFlags(const size_t numFlags, const int newFlagValue, int& setFlags, int& mixedFlags) {
            for (size_t i = 0; i < numFlags; ++i) {
                const bool alreadySet = (newFlagValue & (1 << i)) != 0;
                const bool willBeSet = (setFlags & (1 << i)) != 0;
                if (alreadySet == willBeSet)
                    continue;
                
                setFlags &= ~(1 << i);
                mixedFlags |= (1 << i);
            }
        }
    }
}