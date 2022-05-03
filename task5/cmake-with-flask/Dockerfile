FROM python:3


RUN apt-get update
RUN apt-get install -y python3-pip python-dev cmake make build-essential

RUN mkdir -p ./application
COPY . ./application
WORKDIR ./application
EXPOSE 8898

RUN useradd -ms /bin/bash tp2022user
USER tp2022user

RUN cd /application
RUN mkdir /build
WORKDIR ./application/build
RUN cd ./application/build
RUN cmake ..
RUN make
RUN cd ./application
RUN pip install flask argparse

CMD python3 app.py --port 8898 --host "0.0.0.0"


