# Copyright (C) 2009 Kirtika Ruchandani <kirtibr@gmail.com>
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "Plugins for the hildon marquee, with Mer patches: Part of a messy maemo+mer+ubuntu mixed UI"
HOMEPAGE = "unknown (Ubuntu Mobile home page)"
LICENSE = "GNU Lesser General Public License-version 2.1"
SECTION = "ui"
DEPENDS = "hildon-desktop libdbus-glib"
PR = "r0"

SRC_URI = "http://mirror.anl.gov/pub/ubuntu/pool/universe/m/${PN}/${PN}_${PV}.orig.tar.gz \
           file://marquee-plugins/mer-changes.patch;patch=1"


inherit autotools pkgconfig

do_configure_prepend(){
    for i in `grep -r -l Werror *`;
    do sed -i s:-Werror::g $i;
        done;
}

FILES_${PN} =+ "/usr/lib/hildon-desktop/* "
