FROM fedora
LABEL  author="Vitor Samuel"

RUN yum -y update
RUN yum -y install gcc
RUN yum -y install gcc-c++
RUN yum -y install postgresql-devel
RUN yum -y install libpq-devel
RUN yum -y install rapidxml-devel
RUN yum -y install curl-devel
RUN yum -y install nginx && yum clean all
RUN echo "daemon off;" >> /etc/nginx/nginx.conf
RUN echo "nginx on Fedora" > /usr/share/nginx/html/index.html
COPY * /opt/InterBroker/
RUN ls -ltr /opt/InterBroker
RUN /usr/bin/gcc -Wall -g /opt/InterBroker/main.cpp /opt/InterBroker/process.cpp /opt/InterBroker/tcp/listener.c /opt/InterBroker/tcp/listener.h /opt/InterBroker/tcp/server.h /opt/InterBroker/tcp/server.c /opt/InterBroker/database/lib_version.c /opt/InterBroker/database/lib_version.h /opt/InterBroker/database/server_version.c /opt/InterBroker/database/server_version.h /opt/InterBroker/database/metadata/column_headers.c /opt/InterBroker/database/metadata/column_headers.h /opt/InterBroker/database/operations/create_table.c /opt/InterBroker/database/operations/create_table.h /opt/InterBroker/database/operations/list_tables.c /opt/InterBroker/database/operations/list_tables.h /opt/InterBroker/database/operations/multiple_rows.c /opt/InterBroker/database/operations/multiple_rows.h /opt/InterBroker/database/operations/prepared_statement.c /opt/InterBroker/database/operations/prepared_statement.h /opt/InterBroker/xmlprocessor/rapidxml.hpp                 /opt/InterBroker/xmlprocessor/rapidxml_print.hpp /opt/InterBroker/xmlprocessor/rapidxml_utils.hpp -o /opt/InterBroker/InterBroker -lpthread -lm -lpq -lcurl -lstdc++

EXPOSE 80

CMD /usr/bin