#
# Base Stage
#
FROM gcc:11 as base

LABEL description="Installing dependencies..."

ENV CMAKE_VERSION="3.18"

ENV PROJECT_NAME="cdevenv"

RUN apt-get update && apt-get install -y --no-install-recommends \
        binutils \
        cmake \
        libboost-dev \
        ninja-build \
    && apt-get clean



#
# Build Stage
#
FROM base as build

LABEL description="Building project..."

# Create folder for app service and change directory
WORKDIR /src/app

# Copying all the files from app to container's workdir
COPY . .

# Build the binaries
RUN mkdir build \
    && cd build \
    && cmake .. \
    && make 



#
# VS Code Stage 
# (This is preferred to run as a Docker Dev Environment)
#
FROM base AS vscode

# Get packages for editors and CVS
RUN apt-get update && apt-get install -y \
        cppcheck \
        flawfinder \
        git \
        gdb \
    && apt-get clean

# Create and change user
ENV MYUSERNAME="vscode"

RUN useradd -s /bin/bash -m $MYUSERNAME \
    && groupadd docker \
    && usermod -aG docker $MYUSERNAME

USER $MYUSERNAME

# Keep the container alive
CMD ["sleep", "infinity"]



#
# Production Target Stage 
# Normally called without specifying "target" in compose
#
FROM busybox:glibc

LABEL description="Creating runtime container..."

# Create production ready folder for the binaries and change directory
WORKDIR /usr/local/app

# Copy the binaries from the build to the current directory
COPY --from=build /src/app/build .
    
# Execute the app
CMD ["./src/main"]