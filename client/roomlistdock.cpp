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

#include "roomlistdock.h"

#include "models/roomlistmodel.h"
#include "quaternionroom.h"

RoomListDock::RoomListDock(QWidget* parent)
    : QDockWidget("Rooms", parent)
    , m_connection(nullptr)
{
    //setWidget(new QWidget());
    model = new RoomListModel(this);
    view = new QListView();
    view->setModel(model);
    connect( view, &QListView::activated, this,
             [this](const QModelIndex & index) {
                emit roomSelected( model->roomAt(index.row()) ); });
    setWidget(view);
}

RoomListDock::~RoomListDock()
{ }

void RoomListDock::setConnection( QMatrixClient::Connection* connection )
{
    m_connection = connection;
    model->setConnection(connection);
}
