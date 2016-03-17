TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    lib/bus.c \
    lib/bus_validator.c \
    lib/buses_management.c \
    lib/cleanup.c \
    lib/comparing.c \
    lib/data_loader.c \
    lib/depot.c \
    lib/depot_validator.c \
    lib/depots_management.c \
    lib/dumper.c \
    lib/extracting.c \
    lib/filtering.c \
    lib/list.c \
    lib/membership_management.c \
    lib/messages.c \
    lib/tests.c \
    lib/ui.c \
    lib/ui_printer.c

HEADERS += \
    include/bus.h \
    include/bus_validator.h \
    include/buses_management.h \
    include/cleanup.h \
    include/comparing.h \
    include/data_loader.h \
    include/depot.h \
    include/depot_validator.h \
    include/depots_management.h \
    include/dumper.h \
    include/extracting.h \
    include/filtering.h \
    include/list.h \
    include/membership_management.h \
    include/messages.h \
    include/tests.h \
    include/ui.h \
    include/ui_printer.h
