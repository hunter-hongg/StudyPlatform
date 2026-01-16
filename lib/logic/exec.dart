import 'dart:io';
import 'package:path/path.dart' as path;

class Exec {
  static Future<String> _getCommandPath(String commandName) async {
    final exePath = Platform.resolvedExecutable;
    final appDir = path.dirname(exePath);

    final commandPath = path.join(appDir, 'external', commandName);

    final file = File(commandPath);
    if (!await file.exists()) {
      throw Exception('外部命令不存在: $commandPath');
    }

    return commandPath;
  }

  static Future<int> _runCommand(
    String commandName,
    List<String> arguments, {
    Map<String, String>? environment,
  }) async {
    try {
      final commandPath = await _getCommandPath(commandName);

      final result = await Process.run(
        commandPath,
        arguments,
        environment: environment,
        runInShell: false,
      );

      return result.exitCode;
    } catch (e) {
      return -1;
    }
  }

  static Future<int> exec(String name) async {
    return _runCommand(name, [], environment: Platform.environment);
  }

  static Future<int> run(String name, List<String> args) {
    return _runCommand(name, args, environment: Platform.environment);
  }

  static Future<int> proc(
      String name, List<String> args, Map<String, String> env) {
    return _runCommand(name, args, environment: env);
  }
}
