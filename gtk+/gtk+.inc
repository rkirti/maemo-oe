DESCRIPTION = "GTK+ is a multi-platform toolkit for creating graphical user interfaces. Offering a complete \
set of widgets, GTK+ is suitable for projects ranging from small one-off projects to complete application suites."
HOMEPAGE = "http://www.gtk.org"
SECTION = "libs"
LICENSE = "LGPL"
PRIORITY = "optional"
DEPENDS = "glib-2.0 tiff pango atk jpeg libpng3 libxext libxcursor gtk-doc libgcrypt cups \
           libxrandr libxdamage libxrender libxcomposite"

inherit autotools pkgconfig

LEAD_SONAME = "libgtk-x11-2.0.so"

FILES_${PN} = " ${bindir}/gtk-query-immodules-2.0 \
                ${libdir}/lib*.so.* \
                ${datadir}/themes ${sysconfdir} \
                ${libdir}/gtk-2.0/${LIBV}/engines/libpixmap.so"

FILES_${PN}-dev += " \
        ${datadir}/gtk-2.0/include \
	${libdir}/gtk-2.0/include \
	${bindir}/gdk-pixbuf-csource \
	${bindir}/gtk-builder-convert"

FILES_${PN}-dbg += " \
	${libdir}/gtk-2.0/modules/.debug/* \
	${libdir}/gtk-2.0/${LIBV}/loaders/.debug/* \
	${libdir}/gtk-2.0/${LIBV}/immodules/.debug/* \
	${libdir}/gtk-2.0/${LIBV}/engines/.debug/* \
	${libdir}/gtk-2.0/${LIBV}/printbackends/.debug/*"

NEATSTUFF = " ttf-dejavu-sans gdk-pixbuf-loader-png gdk-pixbuf-loader-jpeg gdk-pixbuf-loader-gif gdk-pixbuf-loader-xpm "

RRECOMMENDS_${PN} = " ${NEATSTUFF} "
RRECOMMENDS_${PN}_linux = " ${NEATSTUFF} glibc-gconv-iso8859-1 "
RRECOMMENDS_${PN}_linux-gnueabi = " ${NEATSTUFF} glibc-gconv-iso8859-1"



do_stage () {
	oe_libinstall -so -C gtk libgtk-x11-2.0 ${STAGING_LIBDIR}
	oe_libinstall -so -C gdk libgdk-x11-2.0 ${STAGING_LIBDIR}
	oe_libinstall -so -C contrib/gdk-pixbuf-xlib libgdk_pixbuf_xlib-2.0 ${STAGING_LIBDIR}
	oe_libinstall -so -C gdk-pixbuf libgdk_pixbuf-2.0 ${STAGING_LIBDIR}
	if test -d modules/other/gail/libgail-util ; then
		oe_libinstall -so -C modules/other/gail/libgail-util libgailutil ${STAGING_LIBDIR}
	fi

	autotools_stage_includes

	mkdir -p ${STAGING_LIBDIR}/gtk-2.0/include
	install -m 0644 gdk/gdkconfig.h ${STAGING_LIBDIR}/gtk-2.0/include/gdkconfig.h
        # Copy over all headers, since the maemo stuff needs access to the private api. *sigh*
	cp gtk/*.h ${STAGING_INCDIR}/gtk-2.0/gtk/

	install -m 0644 m4macros/gtk-2.0.m4 ${STAGING_DATADIR}/aclocal/
}

do_install_append () {
	install -d ${D}${sysconfdir}/gtk-2.0
	rm -f ${D}${libdir}/gtk-2.0/*/*.la ${D}${libdir}/gtk-2.0/${LIBV}/*/*.la
}

postinst_prologue() {
if [ "x$D" != "x" ]; then
  exit 1
fi

}
