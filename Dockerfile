FROM debian:latest
LABEL  author="Vitor"


# update and install dependencies
RUN apt-get update && \
apt-get -y install build-essential gdbserver gdb postgresql libpq-dev librapidxml-dev
COPY * /opt/InterBroker/
RUN ls -ltr /opt/InterBroker
RUN /usr/bin/gcc -Wall -g /opt/InterBroker/main.cpp /opt/InterBroker/process.cpp /opt/InterBroker/tcp/listener.c /opt/InterBroker/tcp/listener.h /opt/InterBroker/tcp/server.h /opt/InterBroker/tcp/server.c /opt/InterBroker/database/lib_version.c /opt/InterBroker/database/lib_version.h /opt/InterBroker/database/server_version.c /opt/InterBroker/database/server_version.h /opt/InterBroker/database/metadata/column_headers.c /opt/InterBroker/database/metadata/column_headers.h /opt/InterBroker/database/operations/create_table.c /opt/InterBroker/database/operations/create_table.h /opt/InterBroker/database/operations/list_tables.c /opt/InterBroker/database/operations/list_tables.h /opt/InterBroker/database/operations/multiple_rows.c /opt/InterBroker/database/operations/multiple_rows.h /opt/InterBroker/database/operations/prepared_statement.c /opt/InterBroker/database/operations/prepared_statement.h /opt/InterBroker/xmlprocessor/rapidxml.hpp                 /opt/InterBroker/xmlprocessor/rapidxml_print.hpp /opt/InterBroker/xmlprocessor/rapidxml_utils.hpp -o /opt/InterBroker/InterBroker -lpthread -lm -lpq -lcurl -lstdc++
CMD /usr/bin