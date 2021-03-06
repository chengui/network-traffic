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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <gtkmm.h>
#include "utils/i18n.hpp"
#include "shareddef.h"
#include "wndmain.hpp"

#if (defined(WIN32) || defined(WINNT))
#include "utils/windowsdef.h"
#endif

int main(int argc, char** argv)
{
#if (defined(WIN32) || defined(WINNT))
    // Verify if current running system fulfil minimum requeriments.
    int retval = check_version();
    if (retval != NO_ERROR)
        return retval;
#endif

    build_package_paths();
    #ifdef TEST
    printf("glade_dir: %s\nlocale_dir: %s\n", glade_dir, locale_dir);
    #endif

    // Gettext initialization
    setlocale(LC_ALL, "");
    bindtextdomain(GETTEXT_PACKAGE, locale_dir);
    bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
    textdomain(GETTEXT_PACKAGE);

    Gtk::Main kit(argc, argv);
    wndMain wndmain;
    kit.run(*wndmain.get_root());

    return (EXIT_SUCCESS);
}

