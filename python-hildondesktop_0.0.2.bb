# Copyright (C) 2009 Kirtika Ruchandani <kirtibr@gmail.com>
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "Python binding for set of widgets provided by libhildondesktop"
HOMEPAGE = "http://maemo.org"
LICENSE = "GNU Lesser General Public License-version 2.1"
SECTION = "libs"
DEPENDS = "hildon-desktop python python-pygtk"
PR = "r0"

SRC_URI = "file://py-hd/hildon-desktop-python-loader.tar.gz \
           file://py-hd/debian-changes.patch;patch=1"

inherit autotools pkgconfig


do_stage(){
    autotools_stage_all
}

PACKAGES = "${PN} hildon-desktop-python-loader"

FILES_hildon-desktop-python-loader = "${libdir}/hildon-desktop/loaders/* "

FILES_${PN} += "${datadir}/pygtk \
                ${libdir}/python2.6" 

