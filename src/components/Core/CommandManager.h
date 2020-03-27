/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of pingnoo (https://github.com/fizzyade/pingnoo)
 * An open source ping path analyser
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FIZZYADE_CORE_COMMANDMANAGER_H
#define FIZZYADE_CORE_COMMANDMANAGER_H

#include "ICommandManager.h"
#include "Menu.h"
#include <QObject>
#include <QString>
#include <QMap>

namespace FizzyAde::Core
{
    class Command;

    /**
     * CommandManager implementation
     *
     * Provides the implementation of an ICommandManager
     *
     */

    class CommandManager :
        public FizzyAde::Core::ICommandManager
    {
        Q_OBJECT

        Q_INTERFACES(FizzyAde::Core::ICommandManager)

    public:
        CommandManager();

        /**
         * @sa ICommandManager
         */

        virtual FizzyAde::Core::ICommand *registerAction(QAction *action, QString id, const FizzyAde::Core::ContextList &contexts);
        virtual void setContext(int contextId);
        virtual FizzyAde::Core::IMenu *createMenu(const QString &identifier, IMenu *parentMenu=nullptr);
        virtual FizzyAde::Core::IMenu *findMenu(const QString &identifier);
        virtual FizzyAde::Core::ICommand *findCommand(const QString &identifier);
    private:

        QMap<QString, Command *> m_commandMap;
        QMap<QString, FizzyAde::Core::Menu *> m_menuMap;
    };
}

#endif // FIZZYADE_CORE_CONTEXTMANAGER_H