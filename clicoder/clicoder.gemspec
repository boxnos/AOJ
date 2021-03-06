# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'clicoder/version'

Gem::Specification.new do |spec|
  spec.name          = "clicoder"
  spec.version       = Clicoder::VERSION
  spec.authors       = ["Genki Sugimoto"]
  spec.email         = ["cfhoyuk.reccos.nelg@gmail.com"]
  spec.description   = %q{Make it easy to deal with online programming contests from the command line}
  spec.summary       = %q{CLI interface to online programming contests}
  spec.homepage      = "https://github.com/Genki-S/clicoder"
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_dependency "nokogiri"
  spec.add_dependency "thor"
  spec.add_dependency "abstract_method"
  spec.add_dependency "launchy"
  spec.add_dependency "mechanize"

  spec.add_development_dependency "bundler"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rspec"
  spec.add_development_dependency "webmock"
  spec.add_development_dependency "cucumber"
  spec.add_development_dependency "aruba"
  spec.add_development_dependency "pry"
end
