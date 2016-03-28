add_library(folly

	folly/folly/Conv.cpp
	folly/folly/Demangle.cpp
	folly/folly/detail/RangeCommon.cpp
	folly/folly/detail/RangeSse42.cpp
	folly/folly/EscapeTables.cpp
	folly/folly/Format.cpp
	folly/folly/FormatTables.cpp
	folly/folly/StringBase.cpp
	folly/folly/String.cpp
	folly/folly/Unicode.cpp

	folly/folly/Bits.cpp
	folly/folly/Checksum.cpp
	folly/folly/detail/CacheLocality.cpp
	folly/folly/dynamic.cpp
	folly/folly/File.cpp
	folly/folly/FileUtil.cpp
	folly/folly/FingerprintTables.cpp
	folly/folly/futures/Barrier.cpp
	folly/folly/futures/ThreadedExecutor.cpp
	folly/folly/futures/Future.cpp
	folly/folly/futures/InlineExecutor.cpp
	folly/folly/futures/ManualExecutor.cpp
	folly/folly/futures/QueuedImmediateExecutor.cpp
	folly/folly/futures/ThreadWheelTimekeeper.cpp
	folly/folly/detail/Futex.cpp
	folly/folly/detail/StaticSingletonManager.cpp
	folly/folly/detail/ThreadLocalDetail.cpp
	folly/folly/GroupVarint.cpp
	folly/folly/GroupVarintTables.cpp
	folly/folly/IPAddress.cpp
	folly/folly/IPAddressV4.cpp
	folly/folly/IPAddressV6.cpp
	folly/folly/LifoSem.cpp
	folly/folly/io/Compression.cpp
	folly/folly/io/IOBuf.cpp
	folly/folly/io/IOBufQueue.cpp
	folly/folly/io/RecordIO.cpp
	folly/folly/io/ShutdownSocketSet.cpp
	folly/folly/io/async/AsyncPipe.cpp
	folly/folly/io/async/AsyncTimeout.cpp
	folly/folly/io/async/AsyncUDPSocket.cpp
	folly/folly/io/async/AsyncServerSocket.cpp
	folly/folly/io/async/AsyncSignalHandler.cpp
	folly/folly/io/async/AsyncSocket.cpp
	folly/folly/io/async/AsyncSSLSocket.cpp
	folly/folly/io/async/EventBase.cpp
	folly/folly/io/async/EventBaseLocal.cpp
	folly/folly/io/async/EventBaseManager.cpp
	folly/folly/io/async/EventHandler.cpp
	folly/folly/io/async/Request.cpp
	folly/folly/io/async/SSLContext.cpp
	folly/folly/io/async/ScopedEventBaseThread.cpp
	folly/folly/io/async/HHWheelTimer.cpp
	folly/folly/io/async/test/SocketPair.cpp
	folly/folly/io/async/test/TimeUtil.cpp
	folly/folly/io/async/ssl/OpenSSLUtils.cpp
	folly/folly/json.cpp
	folly/folly/detail/MemoryIdler.cpp
	folly/folly/MacAddress.cpp
	folly/folly/MemoryMapping.cpp
	folly/folly/portability/Environment.cpp
	folly/folly/portability/Strings.cpp
	folly/folly/portability/SysFile.cpp
	folly/folly/portability/SysStat.cpp
	folly/folly/portability/SysTime.cpp
	folly/folly/portability/Time.cpp
	folly/folly/Random.cpp
	folly/folly/SafeAssert.cpp
	folly/folly/SharedMutex.cpp
	folly/folly/MicroLock.cpp
	folly/folly/Singleton.cpp
	folly/folly/SocketAddress.cpp
	folly/folly/SpookyHashV1.cpp
	folly/folly/SpookyHashV2.cpp
	folly/folly/stats/Instantiations.cpp
	folly/folly/Subprocess.cpp
	folly/folly/ThreadCachedArena.cpp
	folly/folly/TimeoutQueue.cpp
	folly/folly/Uri.cpp
	folly/folly/Version.cpp
	folly/folly/experimental/bser/Dump.cpp
	folly/folly/experimental/bser/Load.cpp
	folly/folly/experimental/fibers/Baton.cpp
	folly/folly/experimental/fibers/Fiber.cpp
	folly/folly/experimental/fibers/FiberManager.cpp
	folly/folly/experimental/fibers/FiberManagerMap.cpp
	folly/folly/experimental/fibers/GuardPageAllocator.cpp
	folly/folly/experimental/fibers/TimeoutController.cpp
	folly/folly/experimental/FunctionScheduler.cpp
	folly/folly/experimental/io/FsUtil.cpp
	folly/folly/experimental/JSONSchema.cpp
	folly/folly/experimental/NestedCommandLineApp.cpp
	folly/folly/experimental/ProgramOptions.cpp
	folly/folly/experimental/Select64.cpp
	folly/folly/experimental/TestUtil.cpp

)

add_custom_command(
    OUTPUT folly/folly/FormatTables.cpp
    COMMAND python build/generate_format_tables.py
    WORKING_DIRECTORY folly/folly/
)

add_custom_command(
    OUTPUT folly/folly/EscapeTables.cpp
    COMMAND python build/generate_escape_tables.py
    WORKING_DIRECTORY folly/folly/
)

add_custom_command(
    OUTPUT folly/folly/GroupVarintTables.cpp
    COMMAND python build/generate_varint_tables.py
    WORKING_DIRECTORY folly/folly/
)

# FormatTables.cpp: build/generate_format_tables.py
# 	$(PYTHON) build/generate_format_tables.py
# CLEANFILES += FormatTables.cpp
# 
# EscapeTables.cpp: build/generate_escape_tables.py
# 	$(PYTHON) build/generate_escape_tables.py
# CLEANFILES += EscapeTables.cpp
# 
# GroupVarintTables.cpp: build/generate_varint_tables.py
# 	$(PYTHON) build/generate_varint_tables.py
# CLEANFILES += GroupVarintTables.cpp

# if HAVE_LINUX
# nobase_follyinclude_HEADERS += \
# 	experimental/io/HugePages.h
# libfolly_la_SOURCES += \
# 	experimental/io/HugePages.cpp
# endif
# 
# if !HAVE_LINUX
# libfollybase_la_SOURCES += detail/Clock.cpp
# endif
# 
# if !HAVE_WEAK_SYMBOLS
# libfollybase_la_SOURCES += detail/MallocImpl.cpp
# endif
# 
# if !HAVE_BITS_FUNCTEXCEPT
# libfollybase_la_SOURCES += detail/FunctionalExcept.cpp
# endif

# target_include_directories(folly PRIVATE /usr/local/include)
target_include_directories(folly PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/folly)

target_compile_options(folly PRIVATE
    -std=gnu++0x
)

