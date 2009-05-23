# Copyright (C) 2009 Kirtika Ruchandani <kirtibr@gmail.com>
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = "X11 XSP extension wire protocol"
HOMEPAGE = "unknown"
LICENSE = "Nokia copyright"
SECTION = "base"
PR = "r1"

SRC_URI = "http://repository.maemo.org/pool/diablo/free/x/${PN}/${PN}_${PV}-1.tar.gz"

inherit autotools pkgconfig

do_stage(){
    autotools_stage_all
}

