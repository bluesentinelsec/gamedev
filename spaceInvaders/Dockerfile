FROM debian:latest

RUN apt update -y
RUN apt install build-essential gdb cmake doxygen python3 python3-pip libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev git vim libxmp-dev pkg-config libfluidsynth-dev fluidsynth libwavpack-dev libopusfile-dev -y

RUN mkdir /spaceInvaders
COPY . /spaceInvaders

RUN git clone https://github.com/emscripten-core/emsdk.git
RUN cd emsdk && ./emsdk install latest
RUN echo ./emsdk activate latest
RUN echo source ./emsdk_env.sh


ENTRYPOINT ["bash"]
