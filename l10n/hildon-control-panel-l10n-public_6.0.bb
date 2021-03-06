# Copyright (C) 2009 Kirtika Ruchandani <kirtibr@gmail.com>
# Released under the MIT license (see COPYING.MIT for the terms)

DESCRIPTION = " Public language files for hildon-control-panel."
HOMEPAGE = "http://maemo.org"
LICENSE = "unknown"
SECTION = "misc"
DEPENDS = "gettext-native"
PR = "r0"

SRC_URI = "http://repository.maemo.org/pool/fremantle/free/h/${PN}/${PN}_${PV}+r6710+0m5.tar.gz"

S = "${WORKDIR}/${PN}-${PV}+r6710+0m5"

TEXT_DOMAIN = "hildon-control-panel"

require hildon-l10n.inc
