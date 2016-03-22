# ExternalProject_Add(nghttp2
#     SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2
#     CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/configure --prefix=<INSTALL_DIR>
#     BUILD_COMMAND ${MAKE})

set(nghttp2_source
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_pq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_map.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_frame.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_buf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_stream.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_outbound_item.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_session.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_submit.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_helper.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_npn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_hd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_hd_huffman.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_hd_huffman_data.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_version.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_priority_spec.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_option.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_callbacks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_mem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_http.c
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_rcbuf.c
)
set(nghttp2_include
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_pq.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_int.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_map.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_queue.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_frame.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_buf.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_session.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_helper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_stream.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_int.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_npn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_submit.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_outbound_item.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_net.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_hd.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_hd_huffman.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_priority_spec.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_option.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_callbacks.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_mem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_http.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/nghttp2_rcbuf.h
)

# file(GLOB_RECURSE nghttp2_include ${CMAKE_CURRENT_SOURCE_DIR}/ftl/include *.h *.hpp)
add_library(nghttp2 ${nghttp2_source} ${nghttp2_include})
target_include_directories(nghttp2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib)
target_include_directories(nghttp2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/nghttp2/lib/includes)
