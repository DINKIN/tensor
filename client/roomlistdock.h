/******************************************************************************
 * Copyright (C) 2015 Felix Rohrbach <kde@fxrh.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ROOMLISTDOCK_H
#define ROOMLISTDOCK_H

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QListView>
#include <QtCore/QStringListModel>

#include "lib/room.h"
#include "lib/connection.h"

class RoomListModel;

class RoomListDock : public QDockWidget
{
        Q_OBJECT
    public:
        RoomListDock(QWidget* parent=0);
        virtual ~RoomListDock();

        void setConnection( QMatrixClient::Connection* m_connection );

    signals:
        void roomSelected(QMatrixClient::Room* room);

    private:
        QMatrixClient::Connection* m_connection;
        QListView* view;
        RoomListModel* model;
};

#endif // ROOMLISTDOCK_H
