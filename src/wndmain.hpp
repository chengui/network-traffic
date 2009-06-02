/*
 * Copyright (C) 2009 Fabrício Godoy <skarllot@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Fabrício Godoy <skarllot@gmail.com>
 *
 */

#ifndef _WNDMAIN_H
#define	_WNDMAIN_H

#include <vector>
#include <gtkmm.h>
#include <libglademm.h>
#include "networkinterface.hpp"

/** Class to manage wndMain Window widget.
 */
class wndMain
{
public:
    wndMain();
    virtual ~wndMain();

    /** Get the cbo_interfaces ComboBox widget.
     *
     * @return The cbo_interfaces widget pointer.
     */
    Gtk::ComboBox* get_cbointerfaces();

    /** Get the top Window widget represented by this instance.
     *
     * @return The wndMain widget pointer.
     */
    Gtk::Window* get_root();

private:

    /** Represents a column record for ComboBox.
     */
    class SingleTextModel : public Gtk::TreeModel::ColumnRecord
    {
    public:
        SingleTextModel()
        {
            add(m_col_name);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    /// The ComboBox that show network interface list.
    Gtk::ComboBox* cbo_interfaces;
    /// The Label that show bytes received by current network interface.
    Gtk::Label* lbl_bytes_received;
    /// The Label that show bytes sent by current network interface.
    Gtk::Label* lbl_bytes_sent;
    /// NetworkInterface instances vector.
    std::vector<NetworkInterface*> network_interfaces;
    /// Pointer to loaded Glade file.
    Glib::RefPtr<Gnome::Glade::Xml> refXml;
    /// The main Window.
    Gtk::Window* wnd_root;

    /** Fill cbo_interfaces with network interface list.
     */
    void fill_cbointerfaces();
    
    /** Called when active item from cbo_interfaces is changed.
     */
    void on_cbointerfaces_changed();
};

#endif	/* _WNDMAIN_H */

