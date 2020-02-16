EDK_PATH=/home/fhh/edk2
BASE_DIR=${PWD}
CFLAGS=-isystem "${PWD}/include" -isystem "${PWD}/drivers/include" -isystem "${EDK_PATH}/MdePkg/Include" -isystem "${EDK_PATH}/MdePkg/Include/X64" -O2
SUBDIRS=drivers
RECURSIVE_MAKE= @for subdir in $(SUBDIRS); \
        do \
        echo "making in $$subdir"; \
        ( cd $$subdir && $(MAKE) all -f Makefile -e BASE_DIR=${BASE_DIR} -e CFLAGS='${CFLAGS}') || exit 1; \
        done

kernel:build/*.o
	$(RECURSIVE_MAKE)
	#ugly.....
	gcc ${CFLAGS} -c helloworld.c -o build/helloworld.o
	ld -e kernel_main build/*.o -o build/kernel
all:kernel
clean:
	rm -rf build/*


	