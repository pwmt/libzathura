# Configure data for version header
conf_data = configuration_data()
conf_data.set('ZVMAJOR', version_array[0])
conf_data.set('ZVMINOR', version_array[1])
conf_data.set('ZVREV',   version_array[2])
conf_data.set('ZVAPI',   so_major)
conf_data.set('ZVABI',   so_minor)
conf_data.set('version',  version)

# Generate version header file
version_header = configure_file(
  input: 'version.h.in',
  output: 'version.h',
  configuration: conf_data
)

# Install version header
install_headers(version_header, subdir: 'libzathura')
